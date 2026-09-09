#include "dockermanager.h"
#include <QDebug>
#include <QRegularExpression>
#include <QStandardPaths>
#include <QFileInfo>

// 获取 Docker 可执行文件的绝对路径，防止 Linux 桌面启动时 PATH 丢失
static QString getDockerExecutablePath() {
    QString path = QStandardPaths::findExecutable("docker");
    if (path.isEmpty()) {
#ifdef Q_OS_LINUX
        if (QFileInfo::exists("/usr/bin/docker")) return "/usr/bin/docker";
        if (QFileInfo::exists("/usr/local/bin/docker")) return "/usr/local/bin/docker";
        if (QFileInfo::exists("/snap/bin/docker")) return "/snap/bin/docker";
#endif
        return "docker"; // 兜底返回默认名称
    }
    return path;
}

DockerManager::DockerManager(QObject *parent) : QObject(parent)
{
    m_process = new QProcess(this);
    
    connect(m_process, &QProcess::readyReadStandardOutput, this, &DockerManager::onReadyReadStandardOutput);
    connect(m_process, &QProcess::readyReadStandardError, this, &DockerManager::onReadyReadStandardError);
    
    // Qt5 and Qt6 compatibility for QProcess::finished
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    connect(m_process, &QProcess::finished, this, &DockerManager::onProcessFinished);
#else
    connect(m_process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this, &DockerManager::onProcessFinished);
#endif

    connect(m_process, &QProcess::errorOccurred, this, &DockerManager::onProcessError);
}

DockerManager::~DockerManager()
{
    if (m_process->state() == QProcess::Running) {
        m_process->kill();
        m_process->waitForFinished(3000);
    }
}

QString DockerManager::translatePathToDocker(const QString &hostPath, const QString &hostMountPath, const QString &containerMountPath) const
{
    if (hostPath.isEmpty()) {
        return "";
    }
    
    QStringList paths = hostPath.split(";");
    QStringList translatedPaths;
    
    for (QString path : paths) {
        path = path.trimmed();
        if (path.isEmpty()) continue;
        
        path.replace("\\", "/");
        
        QString hPath = hostMountPath;
        hPath.replace("\\", "/");
        
        if (path.startsWith(hPath, Qt::CaseInsensitive)) {
            path.replace(0, hPath.length(), containerMountPath);
        }
        translatedPaths << path;
    }
    
    return translatedPaths.join(";");
}

void DockerManager::startTask(const QString &lasFile, const QString &posFile, const QString &outDir, 
                              const QString &iniFile, const QString &configFile,
                              const QString &insposeFile, const QString &metashapeFile, 
                              const QString &imageDir, const QString &maskFile,
                              bool isPan, bool isWhiteModel, bool isDisableFill,
                              const QString &containerName, const QString &hostMountPath, const QString &containerMountPath)
{
    if (isRunning()) {
        emit errorOccurred("任务已在运行，请先停止。");
        return;
    }

    m_outputBuffer.clear();
    m_currentContainerName = containerName;

    QString dockerLas = translatePathToDocker(lasFile, hostMountPath, containerMountPath);
    QString dockerPos = translatePathToDocker(posFile, hostMountPath, containerMountPath);
    QString dockerOut = translatePathToDocker(outDir, hostMountPath, containerMountPath);
    QString dockerIni = translatePathToDocker(iniFile, hostMountPath, containerMountPath);
    QString dockerConfig = translatePathToDocker(configFile, hostMountPath, containerMountPath);
    QString dockerInspose = translatePathToDocker(insposeFile, hostMountPath, containerMountPath);
    QString dockerMetashape = translatePathToDocker(metashapeFile, hostMountPath, containerMountPath);
    QString dockerImageDir = translatePathToDocker(imageDir, hostMountPath, containerMountPath);
    QString dockerMask = translatePathToDocker(maskFile, hostMountPath, containerMountPath);

    QStringList args;
    args << "exec" << "-w" << "/app" << containerName << "python3" << "-u" << "run.py";
    args << "--las_file" << dockerLas;
    
    if (isPan) {
        args << "--posl_file" << dockerPos;
        args << "--pan" << "True";
        
        if (!isWhiteModel) {
            args << "--inspose_file" << dockerInspose;
            args << "--metashape_file" << dockerMetashape;
            args << "--image_dir" << dockerImageDir;
            if (!dockerMask.isEmpty()) {
                args << "--mask_file" << dockerMask;
            }
        }
    } else {
        args << "--pos_file" << dockerPos;
        args << "--pan" << "False";
        
        if (!isWhiteModel) {
            args << "--cam_ini_file" << dockerIni;
            args << "--camera_config" << dockerConfig;
        }
    }
    
    args << "--output_dir" << dockerOut;
    
    if (isWhiteModel) {
        args << "--white_model";
    }
    if (isDisableFill) {
        args << "--disable_fill";
    }

    emit logReady(QString("[SYSTEM] Executing: %1 %2\n").arg(getDockerExecutablePath(), args.join(" ")));
    m_process->start(getDockerExecutablePath(), args);
}

void DockerManager::stopTask()
{
    if (isRunning()) {
        emit logReady("[SYSTEM] 正在中止任务，准备重启容器以强制释放全部底层资源...\n");
        m_process->kill(); // 断开当前 Windows 宿主机的 docker exec 进程
        
        // 使用分离的后台进程静默执行容器重启，-t 1 表示仅给1秒的平滑退出时间，随后直接 SIGKILL
        if (!m_currentContainerName.isEmpty()) {
            QProcess::startDetached(getDockerExecutablePath(), QStringList() << "restart" << "-t" << "1" << m_currentContainerName);
        }
    }
}

bool DockerManager::isRunning() const
{
    return m_process->state() == QProcess::Running;
}

void DockerManager::onReadyReadStandardOutput()
{
    QByteArray data = m_process->readAllStandardOutput();
    QString text = QString::fromUtf8(data);
    emit logReady(text);
    
    m_outputBuffer += text;
    
    // 尝试解析超大文件分割信号
    if (m_outputBuffer.contains("[CHUNK_SPLITTING]")) {
        emit chunkProgressUpdated(-1, 1);
        m_outputBuffer.replace("[CHUNK_SPLITTING]", "");
    }
    
    // 尝试正则解析分块处理进度信息，如 "[CHUNK_PROGRESS] 1/4"
    QRegularExpression re("\\[CHUNK_PROGRESS\\]\\s+(\\d+)/(\\d+)");
    QRegularExpressionMatch match;
    while ((match = re.match(m_outputBuffer)).hasMatch()) {
        int current = match.captured(1).toInt();
        int total = match.captured(2).toInt();
        emit chunkProgressUpdated(current, total);
        
        m_outputBuffer.remove(0, match.capturedEnd());
    }
    
    // 防止缓冲区过大
    if (m_outputBuffer.length() > 10240) {
        m_outputBuffer = m_outputBuffer.right(5120);
    }
}

void DockerManager::onReadyReadStandardError()
{
    QByteArray data = m_process->readAllStandardError();
    QString text = QString::fromUtf8(data);
    emit logReady(text);
    
    m_outputBuffer += text;
    
    // 尝试解析超大文件分割信号
    if (m_outputBuffer.contains("[CHUNK_SPLITTING]")) {
        emit chunkProgressUpdated(-1, 1);
        m_outputBuffer.replace("[CHUNK_SPLITTING]", "");
    }
    
    // 尝试正则解析分块处理进度信息，如 "[CHUNK_PROGRESS] 1/4"
    QRegularExpression re("\\[CHUNK_PROGRESS\\]\\s+(\\d+)/(\\d+)");
    QRegularExpressionMatch match;
    while ((match = re.match(m_outputBuffer)).hasMatch()) {
        int current = match.captured(1).toInt();
        int total = match.captured(2).toInt();
        emit chunkProgressUpdated(current, total);
        
        m_outputBuffer.remove(0, match.capturedEnd());
    }
    
    // 防止缓冲区过大
    if (m_outputBuffer.length() > 10240) {
        m_outputBuffer = m_outputBuffer.right(5120);
    }
}

void DockerManager::onProcessFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    emit taskFinished(exitCode, exitStatus);
}

void DockerManager::onProcessError(QProcess::ProcessError error)
{
    emit errorOccurred(QString("QProcess Error: %1").arg(error));
}

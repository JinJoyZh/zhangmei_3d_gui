#ifndef DOCKERMANAGER_H
#define DOCKERMANAGER_H

#include <QObject>
#include <QProcess>
#include <QString>

class DockerManager : public QObject
{
    Q_OBJECT
public:
    explicit DockerManager(QObject *parent = nullptr);
    ~DockerManager();

    // 启动任务
    void startTask(const QString &lasFile, const QString &posFile, const QString &outDir, 
                   const QString &iniFile, const QString &configFile,
                   const QString &insposeFile, const QString &metashapeFile, 
                   const QString &imageDir, const QString &maskFile,
                   bool isPan, bool isWhiteModel, bool isDisableFill,
                   const QString &containerName, const QString &hostMountPath, const QString &containerMountPath);
    
    // 中止任务
    void stopTask();

    // 判断是否在运行
    bool isRunning() const;

    // 查找宿主机 Docker CLI，兼容桌面启动时 PATH 不完整的 Linux 环境
    static QString dockerExecutable();

signals:
    void logReady(const QString &log);
    void chunkProgressUpdated(int current, int total);
    void taskFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void errorOccurred(const QString &errorMsg);

private slots:
    void onReadyReadStandardOutput();
    void onReadyReadStandardError();
    void onProcessFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void onProcessError(QProcess::ProcessError error);

private:
    QProcess *m_process;
    QString m_outputBuffer;
    QString m_currentContainerName;
    QString m_currentDockerExecutable;
    
    // 路径映射函数：Windows 路径 -> Docker 容器内的挂载路径
    QString translatePathToDocker(const QString &hostPath, const QString &hostMountPath, const QString &containerMountPath) const;
};

#endif // DOCKERMANAGER_H

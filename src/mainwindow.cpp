#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "configdialog.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QScrollBar>
#include <QProcess>
#include <QApplication>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_dockerManager = new DockerManager(this);

    connect(m_dockerManager, &DockerManager::logReady, this, &MainWindow::appendLog);
    connect(m_dockerManager, &DockerManager::chunkProgressUpdated, this, &MainWindow::updateChunkProgress);
    connect(m_dockerManager, &DockerManager::taskFinished, this, &MainWindow::onTaskFinished);
    connect(m_dockerManager, &DockerManager::errorOccurred, this, &MainWindow::onTaskError);

    // 动态更新输出目录的前缀提示
    connect(ui->lineEditHostPath, &QLineEdit::textChanged, this, [this](const QString &text){
        QString cleanText = text;
        cleanText.replace("\\", "/");
        if (!cleanText.endsWith("/")) {
            cleanText += "/";
        }
        ui->labelOutBase->setText(cleanText);
    });
    // 触发一次初始化
    emit ui->lineEditHostPath->textChanged(ui->lineEditHostPath->text());

    // Initialize UI state based on pan mode and white model mode
    on_chkPan_toggled(ui->chkPan->isChecked());
    on_chkWhiteModel_toggled(ui->chkWhiteModel->isChecked());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnBrowseLas_clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(this, "选择 LAS 点云文件 (支持多选)", "", "LAS Files (*.las);;All Files (*)");
    if (!files.isEmpty()) {
        ui->lineEditLas->setText(files.join(";"));
    }
}

void MainWindow::on_btnBrowsePos_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, "选择 POS 轨迹文件", "", "POS Files (*.txt *.PosL *.pos);;All Files (*)");
    if (!file.isEmpty()) {
        ui->lineEditPos->setText(file);
    }
}

void MainWindow::on_btnBrowseIni_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, "选择相机标定文件", "", "INI Files (*.ini);;All Files (*.*)");
    if (!file.isEmpty()) {
        ui->lineEditIni->setText(file);
    }
}

void MainWindow::on_btnBrowseConfig_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, "选择相机配置文件", "", "JSON Files (*.json);;All Files (*.*)");
    if (!file.isEmpty()) {
        ui->lineEditConfig->setText(file);
    }
}

void MainWindow::on_btnExportConfigTemplate_clicked()
{
    QString savePath = QFileDialog::getSaveFileName(this, "导出相机配置模板", "camera_config_template.json", "JSON Files (*.json)");
    if (savePath.isEmpty()) {
        return;
    }

    QFile file(savePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "导出失败", "无法创建文件，请检查目录权限！");
        return;
    }

    QTextStream out(&file);
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    out.setCodec("UTF-8");
#endif
    out.setGenerateByteOrderMark(true); // 可选，生成 BOM 头以便一些 Windows 编辑器更好地识别 UTF-8

    // 为了确保中文字符串字面量能被正确编码，我们将其转换为 UTF-8 字节数组后再写入
    out << QString::fromUtf8("{\n"
        "    \"road_cameras\": [\n"
        "        {\n"
        "            \"name\": \"<相机标识，需与ini文件一致，如 Camera3>\",\n"
        "            \"img_dir\": \"<容器内该相机图像的存放目录>\",\n"
        "            \"pos_file\": \"<容器内该相机位姿文件的路径>\",\n"
        "            \"mask\": \"<可选，该相机专属掩膜图像的容器内路径。掩膜中黑色区域代表需要剔除的车体遮挡，白色区域代表保留用于贴图的有效场景>\"\n"
        "        },\n"
        "        {\n"
        "            \"name\": \"<相机标识，如 Camera4>\",\n"
        "            \"img_dir\": \"<容器内该相机图像的存放目录>\",\n"
        "            \"pos_file\": \"<容器内该相机位姿文件的路径>\",\n"
        "            \"mask\": \"<可选，该相机专属掩膜图像的容器内路径>\"\n"
        "        }\n"
        "    ],\n"
        "    \"sign_cameras\": [\n"
        "        {\n"
        "            \"name\": \"<相机标识，如 Camera1>\",\n"
        "            \"img_dir\": \"<容器内该相机图像的存放目录>\",\n"
        "            \"pos_file\": \"<容器内该相机位姿文件的路径>\"\n"
        "        },\n"
        "        {\n"
        "            \"name\": \"<相机标识，如 Camera2>\",\n"
        "            \"img_dir\": \"<容器内该相机图像的存放目录>\",\n"
        "            \"pos_file\": \"<容器内该相机位姿文件的路径>\"\n"
        "        }\n"
        "    ]\n"
        "}\n");
    file.close();

    QString msg = QString("模板已成功导出至：\n%1\n\n【配置字段说明】\n"
                          "- road_cameras: 专用于路面网格贴图的相机组（推荐填入无车体遮挡的左后、右后相机）。\n"
                          "- sign_cameras: 专用于路牌/立面重构的相机组（推荐填入高清前向相机，不参与路面贴图）。\n"
                          "- mask: 可选，专属掩膜图像的容器内路径（黑色RGB<128代表剔除遮挡，白色代表保留）。\n"
                          "- pos_file: 该相机的位姿记录文件（imgpost.txt）。")
                  .arg(savePath);

    QMessageBox::information(this, "导出成功", msg);
}

void MainWindow::on_btnBrowseInspose_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, "选择 INSPose 位姿文件", "", "Text Files (*.txt *.dd);;All Files (*)");
    if (!file.isEmpty()) {
        ui->lineEditInspose->setText(file);
    }
}

void MainWindow::on_btnBrowseMetashape_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, "选择 Metashape 相机位置文件", "", "Text Files (*.txt);;All Files (*)");
    if (!file.isEmpty()) {
        ui->lineEditMetashape->setText(file);
    }
}

void MainWindow::on_btnBrowseImageDir_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, "选择全景图像目录", "");
    if (!dir.isEmpty()) {
        ui->lineEditImageDir->setText(dir);
    }
}

void MainWindow::on_btnBrowseMask_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, "选择 Mask 遮罩图文件", "", "Image Files (*.png *.jpg);;All Files (*)");
    if (!file.isEmpty()) {
        ui->lineEditMask->setText(file);
    }
}

void MainWindow::on_chkWhiteModel_toggled(bool checked)
{
    bool isPan = ui->chkPan->isChecked();
    bool enableMultiCamArgs = !isPan && !checked;
    bool enablePanArgs = isPan && !checked;

    // 多目纹理参数
    ui->labelIni->setEnabled(enableMultiCamArgs);
    ui->lineEditIni->setEnabled(enableMultiCamArgs);
    ui->btnBrowseIni->setEnabled(enableMultiCamArgs);
    
    ui->labelConfig->setEnabled(enableMultiCamArgs);
    ui->lineEditConfig->setEnabled(enableMultiCamArgs);
    ui->btnBrowseConfig->setEnabled(enableMultiCamArgs);
    
    // 全景纹理参数
    ui->labelInspose->setEnabled(enablePanArgs);
    ui->lineEditInspose->setEnabled(enablePanArgs);
    ui->btnBrowseInspose->setEnabled(enablePanArgs);
    
    ui->labelMetashape->setEnabled(enablePanArgs);
    ui->lineEditMetashape->setEnabled(enablePanArgs);
    ui->btnBrowseMetashape->setEnabled(enablePanArgs);
    
    ui->labelImageDir->setEnabled(enablePanArgs);
    ui->lineEditImageDir->setEnabled(enablePanArgs);
    ui->btnBrowseImageDir->setEnabled(enablePanArgs);
    
    ui->labelMask->setEnabled(enablePanArgs);
    ui->lineEditMask->setEnabled(enablePanArgs);
    ui->btnBrowseMask->setEnabled(enablePanArgs);
}

void MainWindow::on_chkPan_toggled(bool checked)
{
    Q_UNUSED(checked);
    // 复用白模逻辑来更新联动状态
    on_chkWhiteModel_toggled(ui->chkWhiteModel->isChecked());
}

void MainWindow::on_btnStart_clicked()
{
    QString lasFile = ui->lineEditLas->text().trimmed();
    QString posFile = ui->lineEditPos->text().trimmed();
    QString relOutDir = ui->lineEditOut->text().trimmed();
    QString iniFile = ui->lineEditIni->text().trimmed();
    QString configFile = ui->lineEditConfig->text().trimmed();
    QString insposeFile = ui->lineEditInspose->text().trimmed();
    QString metashapeFile = ui->lineEditMetashape->text().trimmed();
    QString imageDir = ui->lineEditImageDir->text().trimmed();
    QString maskFile = ui->lineEditMask->text().trimmed();

    QString containerName = ui->lineEditContainerName->text().trimmed();
    QString hostMountPath = ui->lineEditHostPath->text().trimmed();
    QString containerMountPath = ui->lineEditContainerPath->text().trimmed();

    bool isPan = ui->chkPan->isChecked();
    bool isWhiteModel = ui->chkWhiteModel->isChecked();
    bool isDisableFill = ui->chkDisableFill->isChecked();

    if (lasFile.isEmpty() || posFile.isEmpty() || relOutDir.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "请确保填写了 LAS 文件、POS 文件和输出子目录！");
        return;
    }
    
    if (containerName.isEmpty() || hostMountPath.isEmpty() || containerMountPath.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "请确保填写了完整的 Docker 环境配置参数！");
        return;
    }

    // 动态组装并格式化真实的输出目录绝对路径
    QString hostMountClean = hostMountPath;
    hostMountClean.replace("\\", "/");
    if (!hostMountClean.endsWith("/")) {
        hostMountClean += "/";
    }
    QString outDir = hostMountClean + relOutDir;

    // 路径越界安全校验器：确保所有路径都位于挂载目录内
    auto validatePathInMount = [&](const QString& path, const QString& pathName) -> bool {
        if (path.isEmpty()) return true;
        
        QString normalizedPath = path;
        normalizedPath.replace("\\", "/");
        QString normalizedMount = hostMountPath;
        normalizedMount.replace("\\", "/");
        
        if (!normalizedPath.startsWith(normalizedMount, Qt::CaseInsensitive)) {
            QMessageBox::warning(this, "路径越界错误", 
                QString("【%1】必须位于挂载目录内！\n\n"
                        "当前路径：%2\n"
                        "挂载目录：%3\n\n"
                        "因为 Docker 容器只能访问挂载进去的目录，选择外部目录将导致容器无法读取或写入文件。")
                .arg(pathName, path, hostMountPath));
            return false;
        }
        return true;
    };

    if (!validatePathInMount(lasFile, "LAS 点云文件") ||
        !validatePathInMount(posFile, "POS 轨迹文件")) {
        return;
    }

    // 如果不是白模模式且不是全景模式，则必须提供相机参数
    if (!isPan && !isWhiteModel) {
        if (iniFile.isEmpty() || configFile.isEmpty()) {
            QMessageBox::warning(this, "输入错误", "多目相机贴图模式下，必须提供【相机标定(.ini)】和【相机配置(.json)】文件！\n\n如果您只想生成几何模型，请勾选【白模模式】。");
            return;
        }
        if (!validatePathInMount(iniFile, "相机标定文件") ||
            !validatePathInMount(configFile, "相机配置文件")) {
            return;
        }
    }
    
    // 如果是全景纹理模式，则必须提供全景贴图相关参数
    if (isPan && !isWhiteModel) {
        if (insposeFile.isEmpty() || metashapeFile.isEmpty() || imageDir.isEmpty()) {
            QMessageBox::warning(this, "输入错误", "全景贴图模式下，必须提供【INSPose文件】、【Metashape文件】和【全景图像目录】！\n\n如果您只想生成几何模型，请勾选【白模模式】。");
            return;
        }
        if (!validatePathInMount(insposeFile, "INSPose 文件") ||
            !validatePathInMount(metashapeFile, "Metashape 文件") ||
            !validatePathInMount(imageDir, "全景图像目录") ||
            !validatePathInMount(maskFile, "Mask 遮罩图")) {
            return;
        }
    }

    ui->btnStart->setEnabled(false);
    ui->btnStop->setEnabled(true);
    
    // Disable other UI components during execution
    ui->btnRestartDocker->setEnabled(false);
    ui->btnConfig->setEnabled(false);
    ui->groupBoxDocker->setEnabled(false);
    ui->groupBoxInput->setEnabled(false);
    ui->groupBoxOptions->setEnabled(false);
    
    ui->progressBar->setMaximum(1);
    ui->progressBar->setValue(0);
    ui->progressBar->setFormat(QString("Docker 初始化与预处理中..."));
    ui->textEditLog->clear();

    appendLog("[SYSTEM] 启动任务...");
    m_dockerManager->startTask(lasFile, posFile, outDir, iniFile, configFile, 
                               insposeFile, metashapeFile, imageDir, maskFile,
                               isPan, isWhiteModel, isDisableFill,
                               containerName, hostMountPath, containerMountPath);
}

void MainWindow::on_btnStop_clicked()
{
    m_dockerManager->stopTask();
}

void MainWindow::on_btnConfig_clicked()
{
    QString hostMountPath = ui->lineEditHostPath->text().trimmed();
    QString hostMountClean = hostMountPath;
    hostMountClean.replace("\\", "/");
    if (!hostMountClean.endsWith("/")) {
        hostMountClean += "/";
    }
    QString configPath = hostMountClean + "config.yaml";
    
    ConfigDialog dialog(configPath, this);
    dialog.exec();
}

void MainWindow::on_btnRestartDocker_clicked()
{
    QString containerName = ui->lineEditContainerName->text().trimmed();
    if (containerName.isEmpty()) {
        containerName = "zhongmei_3d";
    }
    
    // Disable all other UI components
    ui->btnRestartDocker->setEnabled(false);
    ui->btnRestartDocker->setText("重启中...");
    ui->btnConfig->setEnabled(false);
    ui->groupBoxDocker->setEnabled(false);
    ui->groupBoxInput->setEnabled(false);
    ui->groupBoxOptions->setEnabled(false);
    ui->btnStart->setEnabled(false);
    ui->btnStop->setEnabled(false);
    
    QProcess *process = new QProcess(this);
    
    connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), 
            [this, process, containerName](int exitCode, QProcess::ExitStatus exitStatus) {
        if (exitCode == 0 && exitStatus == QProcess::NormalExit) {
            // 这里的 QMessageBox 会阻塞当前代码执行，直到用户点击“确定”关闭弹窗
            QMessageBox::information(this, "成功", QString("容器 '%1' 重启成功！").arg(containerName));
        } else {
            QString err = QString::fromUtf8(process->readAllStandardError());
            QMessageBox::critical(this, "失败", QString("容器 '%1' 重启失败！\n%2").arg(containerName).arg(err));
        }
        
        // Restore UI components ONLY AFTER the user clicks OK on the dialog
        ui->btnRestartDocker->setEnabled(true);
        ui->btnRestartDocker->setText("重启容器");
        ui->btnConfig->setEnabled(true);
        ui->groupBoxDocker->setEnabled(true);
        ui->groupBoxInput->setEnabled(true);
        ui->groupBoxOptions->setEnabled(true);
        ui->btnStart->setEnabled(!m_dockerManager->isRunning());
        ui->btnStop->setEnabled(m_dockerManager->isRunning());
        
        process->deleteLater();
    });
    
    connect(process, &QProcess::errorOccurred, 
            [this, process](QProcess::ProcessError error) {
        if (error == QProcess::FailedToStart) {
            QMessageBox::critical(this, "失败", "无法启动 Docker 命令，请检查环境配置。");
            
            ui->btnRestartDocker->setEnabled(true);
            ui->btnRestartDocker->setText("重启容器");
            ui->btnConfig->setEnabled(true);
            ui->groupBoxDocker->setEnabled(true);
            ui->groupBoxInput->setEnabled(true);
            ui->groupBoxOptions->setEnabled(true);
            ui->btnStart->setEnabled(!m_dockerManager->isRunning());
            ui->btnStop->setEnabled(m_dockerManager->isRunning());
            
            process->deleteLater();
        }
    });
    
    process->start("docker", QStringList() << "restart" << containerName);
}

void MainWindow::appendLog(const QString &log)
{
    // Move cursor to the end before inserting to prevent log inversion
    QTextCursor cursor = ui->textEditLog->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->textEditLog->setTextCursor(cursor);
    
    ui->textEditLog->insertPlainText(log);
    ui->textEditLog->verticalScrollBar()->setValue(ui->textEditLog->verticalScrollBar()->maximum());
}

void MainWindow::updateChunkProgress(int current, int total)
{
    ui->progressBar->setMaximum(total);
    if (current == -1) { // Special code for splitting
        ui->progressBar->setFormat(QString("正在分割超大点云文件..."));
        return;
    }
    
    if (current > total) {
        ui->progressBar->setValue(total);
        ui->progressBar->setFormat(QString("处理完成！共 %1 块").arg(total));
    } else {
        ui->progressBar->setValue(current - 1);
        ui->progressBar->setFormat(QString("正在处理分块: 第 %1 / %2 块").arg(current).arg(total));
    }
}

void MainWindow::onTaskFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    ui->btnStart->setEnabled(true);
    ui->btnStop->setEnabled(false);
    
    // Restore other UI components
    ui->btnRestartDocker->setEnabled(true);
    ui->btnConfig->setEnabled(true);
    ui->groupBoxDocker->setEnabled(true);
    ui->groupBoxInput->setEnabled(true);
    ui->groupBoxOptions->setEnabled(true);
    
    if (exitStatus == QProcess::CrashExit) {
        appendLog(QString("\n[SYSTEM] 任务被强行终止。"));
        ui->progressBar->setFormat(QString("任务已终止"));
    } else if (exitCode != 0) {
        appendLog(QString("\n[SYSTEM] 任务异常中断，退出码: %1").arg(exitCode));
        ui->progressBar->setFormat(QString("处理中断 (退出码: %1)").arg(exitCode));
    } else {
        appendLog(QString("\n[SYSTEM] 任务正常结束，退出码: 0"));
        if (ui->progressBar->maximum() > 0) {
            ui->progressBar->setValue(ui->progressBar->maximum());
            ui->progressBar->setFormat(QString("处理完成！共 %1 块").arg(ui->progressBar->maximum()));
        }
    }
}

void MainWindow::onTaskError(const QString &errorMsg)
{
    appendLog(QString("\n[ERROR] %1").arg(errorMsg));
    ui->btnStart->setEnabled(true);
    ui->btnStop->setEnabled(false);
    
    // Restore other UI components
    ui->btnRestartDocker->setEnabled(true);
    ui->btnConfig->setEnabled(true);
    ui->groupBoxDocker->setEnabled(true);
    ui->groupBoxInput->setEnabled(true);
    ui->groupBoxOptions->setEnabled(true);
}

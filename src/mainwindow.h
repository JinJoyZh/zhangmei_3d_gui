#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dockermanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_btnBrowseLas_clicked();
    void on_btnBrowsePos_clicked();
    void on_btnBrowseIni_clicked();
    void on_btnBrowseConfig_clicked();
    void on_btnBrowseInspose_clicked();
    void on_btnBrowseMetashape_clicked();
    void on_btnBrowseImageDir_clicked();
    void on_btnBrowseMask_clicked();
    void on_chkPan_toggled(bool checked);
    void on_chkWhiteModel_toggled(bool checked);   
    void on_btnStart_clicked();
    void on_btnStop_clicked();
    void on_btnConfig_clicked();
    void on_btnRestartDocker_clicked();
    void on_btnExportConfigTemplate_clicked();

    void appendLog(const QString &log);
    void updateChunkProgress(int current, int total);
    void onTaskFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void onTaskError(const QString &errorMsg);

private:
    Ui::MainWindow *ui;
    DockerManager *m_dockerManager;
};

#endif // MAINWINDOW_H

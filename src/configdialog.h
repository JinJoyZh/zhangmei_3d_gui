#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>

namespace Ui {
class ConfigDialog;
}

class ConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigDialog(const QString &configFilePath, QWidget *parent = nullptr);
    ~ConfigDialog();

private slots:
    void on_btnRestoreDefault_clicked();
    void on_btnSave_clicked();
    void on_btnCancel_clicked();

private:
    Ui::ConfigDialog *ui;
    QString m_configFilePath;
    QString m_currentYamlContent;
    
    void loadConfig();
    void parseYamlToUI();
    void saveUIToYaml();
    QString updateYamlValue(QString yaml, const QString& section, const QString& key, const QString& val);
};

#endif // CONFIGDIALOG_H

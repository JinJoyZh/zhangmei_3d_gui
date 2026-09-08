/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayoutTopConfig;
    QPushButton *btnRestartDocker;
    QSpacerItem *horizontalSpacerTop;
    QPushButton *btnConfig;
    QGroupBox *groupBoxDocker;
    QGridLayout *gridLayoutDocker;
    QLabel *labelContainerName;
    QLineEdit *lineEditContainerName;
    QLabel *labelHostPath;
    QLineEdit *lineEditHostPath;
    QLabel *labelContainerPath;
    QLineEdit *lineEditContainerPath;
    QGroupBox *groupBoxInput;
    QGridLayout *gridLayout;
    QLabel *labelLas;
    QLineEdit *lineEditLas;
    QPushButton *btnBrowseLas;
    QLabel *labelPos;
    QLineEdit *lineEditPos;
    QPushButton *btnBrowsePos;
    QLabel *labelInspose;
    QLineEdit *lineEditInspose;
    QPushButton *btnBrowseInspose;
    QLabel *labelMetashape;
    QLineEdit *lineEditMetashape;
    QPushButton *btnBrowseMetashape;
    QLabel *labelImageDir;
    QLineEdit *lineEditImageDir;
    QPushButton *btnBrowseImageDir;
    QLabel *labelMask;
    QLineEdit *lineEditMask;
    QPushButton *btnBrowseMask;
    QLabel *labelIni;
    QLineEdit *lineEditIni;
    QPushButton *btnBrowseIni;
    QHBoxLayout *horizontalLayoutConfig;
    QLabel *labelConfig;
    QPushButton *btnExportConfigTemplate;
    QLineEdit *lineEditConfig;
    QPushButton *btnBrowseConfig;
    QLabel *labelOut;
    QHBoxLayout *horizontalLayoutOut;
    QLabel *labelOutBase;
    QLineEdit *lineEditOut;
    QGroupBox *groupBoxOptions;
    QHBoxLayout *horizontalLayout;
    QCheckBox *chkPan;
    QCheckBox *chkWhiteModel;
    QCheckBox *chkDisableFill;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnStart;
    QPushButton *btnStop;
    QProgressBar *progressBar;
    QGroupBox *groupBoxLog;
    QVBoxLayout *verticalLayoutLog;
    QTextEdit *textEditLog;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayoutTopConfig = new QHBoxLayout();
        horizontalLayoutTopConfig->setObjectName(QString::fromUtf8("horizontalLayoutTopConfig"));
        btnRestartDocker = new QPushButton(centralwidget);
        btnRestartDocker->setObjectName(QString::fromUtf8("btnRestartDocker"));

        horizontalLayoutTopConfig->addWidget(btnRestartDocker);

        horizontalSpacerTop = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutTopConfig->addItem(horizontalSpacerTop);

        btnConfig = new QPushButton(centralwidget);
        btnConfig->setObjectName(QString::fromUtf8("btnConfig"));

        horizontalLayoutTopConfig->addWidget(btnConfig);


        verticalLayout->addLayout(horizontalLayoutTopConfig);

        groupBoxDocker = new QGroupBox(centralwidget);
        groupBoxDocker->setObjectName(QString::fromUtf8("groupBoxDocker"));
        gridLayoutDocker = new QGridLayout(groupBoxDocker);
        gridLayoutDocker->setObjectName(QString::fromUtf8("gridLayoutDocker"));
        labelContainerName = new QLabel(groupBoxDocker);
        labelContainerName->setObjectName(QString::fromUtf8("labelContainerName"));

        gridLayoutDocker->addWidget(labelContainerName, 0, 0, 1, 1);

        lineEditContainerName = new QLineEdit(groupBoxDocker);
        lineEditContainerName->setObjectName(QString::fromUtf8("lineEditContainerName"));

        gridLayoutDocker->addWidget(lineEditContainerName, 0, 1, 1, 1);

        labelHostPath = new QLabel(groupBoxDocker);
        labelHostPath->setObjectName(QString::fromUtf8("labelHostPath"));

        gridLayoutDocker->addWidget(labelHostPath, 1, 0, 1, 1);

        lineEditHostPath = new QLineEdit(groupBoxDocker);
        lineEditHostPath->setObjectName(QString::fromUtf8("lineEditHostPath"));

        gridLayoutDocker->addWidget(lineEditHostPath, 1, 1, 1, 1);

        labelContainerPath = new QLabel(groupBoxDocker);
        labelContainerPath->setObjectName(QString::fromUtf8("labelContainerPath"));

        gridLayoutDocker->addWidget(labelContainerPath, 2, 0, 1, 1);

        lineEditContainerPath = new QLineEdit(groupBoxDocker);
        lineEditContainerPath->setObjectName(QString::fromUtf8("lineEditContainerPath"));

        gridLayoutDocker->addWidget(lineEditContainerPath, 2, 1, 1, 1);


        verticalLayout->addWidget(groupBoxDocker);

        groupBoxInput = new QGroupBox(centralwidget);
        groupBoxInput->setObjectName(QString::fromUtf8("groupBoxInput"));
        gridLayout = new QGridLayout(groupBoxInput);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelLas = new QLabel(groupBoxInput);
        labelLas->setObjectName(QString::fromUtf8("labelLas"));

        gridLayout->addWidget(labelLas, 0, 0, 1, 1);

        lineEditLas = new QLineEdit(groupBoxInput);
        lineEditLas->setObjectName(QString::fromUtf8("lineEditLas"));

        gridLayout->addWidget(lineEditLas, 0, 1, 1, 1);

        btnBrowseLas = new QPushButton(groupBoxInput);
        btnBrowseLas->setObjectName(QString::fromUtf8("btnBrowseLas"));

        gridLayout->addWidget(btnBrowseLas, 0, 2, 1, 1);

        labelPos = new QLabel(groupBoxInput);
        labelPos->setObjectName(QString::fromUtf8("labelPos"));

        gridLayout->addWidget(labelPos, 1, 0, 1, 1);

        lineEditPos = new QLineEdit(groupBoxInput);
        lineEditPos->setObjectName(QString::fromUtf8("lineEditPos"));

        gridLayout->addWidget(lineEditPos, 1, 1, 1, 1);

        btnBrowsePos = new QPushButton(groupBoxInput);
        btnBrowsePos->setObjectName(QString::fromUtf8("btnBrowsePos"));

        gridLayout->addWidget(btnBrowsePos, 1, 2, 1, 1);

        labelInspose = new QLabel(groupBoxInput);
        labelInspose->setObjectName(QString::fromUtf8("labelInspose"));

        gridLayout->addWidget(labelInspose, 2, 0, 1, 1);

        lineEditInspose = new QLineEdit(groupBoxInput);
        lineEditInspose->setObjectName(QString::fromUtf8("lineEditInspose"));

        gridLayout->addWidget(lineEditInspose, 2, 1, 1, 1);

        btnBrowseInspose = new QPushButton(groupBoxInput);
        btnBrowseInspose->setObjectName(QString::fromUtf8("btnBrowseInspose"));

        gridLayout->addWidget(btnBrowseInspose, 2, 2, 1, 1);

        labelMetashape = new QLabel(groupBoxInput);
        labelMetashape->setObjectName(QString::fromUtf8("labelMetashape"));

        gridLayout->addWidget(labelMetashape, 3, 0, 1, 1);

        lineEditMetashape = new QLineEdit(groupBoxInput);
        lineEditMetashape->setObjectName(QString::fromUtf8("lineEditMetashape"));

        gridLayout->addWidget(lineEditMetashape, 3, 1, 1, 1);

        btnBrowseMetashape = new QPushButton(groupBoxInput);
        btnBrowseMetashape->setObjectName(QString::fromUtf8("btnBrowseMetashape"));

        gridLayout->addWidget(btnBrowseMetashape, 3, 2, 1, 1);

        labelImageDir = new QLabel(groupBoxInput);
        labelImageDir->setObjectName(QString::fromUtf8("labelImageDir"));

        gridLayout->addWidget(labelImageDir, 4, 0, 1, 1);

        lineEditImageDir = new QLineEdit(groupBoxInput);
        lineEditImageDir->setObjectName(QString::fromUtf8("lineEditImageDir"));

        gridLayout->addWidget(lineEditImageDir, 4, 1, 1, 1);

        btnBrowseImageDir = new QPushButton(groupBoxInput);
        btnBrowseImageDir->setObjectName(QString::fromUtf8("btnBrowseImageDir"));

        gridLayout->addWidget(btnBrowseImageDir, 4, 2, 1, 1);

        labelMask = new QLabel(groupBoxInput);
        labelMask->setObjectName(QString::fromUtf8("labelMask"));

        gridLayout->addWidget(labelMask, 5, 0, 1, 1);

        lineEditMask = new QLineEdit(groupBoxInput);
        lineEditMask->setObjectName(QString::fromUtf8("lineEditMask"));

        gridLayout->addWidget(lineEditMask, 5, 1, 1, 1);

        btnBrowseMask = new QPushButton(groupBoxInput);
        btnBrowseMask->setObjectName(QString::fromUtf8("btnBrowseMask"));

        gridLayout->addWidget(btnBrowseMask, 5, 2, 1, 1);

        labelIni = new QLabel(groupBoxInput);
        labelIni->setObjectName(QString::fromUtf8("labelIni"));

        gridLayout->addWidget(labelIni, 6, 0, 1, 1);

        lineEditIni = new QLineEdit(groupBoxInput);
        lineEditIni->setObjectName(QString::fromUtf8("lineEditIni"));

        gridLayout->addWidget(lineEditIni, 6, 1, 1, 1);

        btnBrowseIni = new QPushButton(groupBoxInput);
        btnBrowseIni->setObjectName(QString::fromUtf8("btnBrowseIni"));

        gridLayout->addWidget(btnBrowseIni, 6, 2, 1, 1);

        horizontalLayoutConfig = new QHBoxLayout();
        horizontalLayoutConfig->setObjectName(QString::fromUtf8("horizontalLayoutConfig"));
        labelConfig = new QLabel(groupBoxInput);
        labelConfig->setObjectName(QString::fromUtf8("labelConfig"));

        horizontalLayoutConfig->addWidget(labelConfig);

        btnExportConfigTemplate = new QPushButton(groupBoxInput);
        btnExportConfigTemplate->setObjectName(QString::fromUtf8("btnExportConfigTemplate"));

        horizontalLayoutConfig->addWidget(btnExportConfigTemplate);


        gridLayout->addLayout(horizontalLayoutConfig, 7, 0, 1, 1);

        lineEditConfig = new QLineEdit(groupBoxInput);
        lineEditConfig->setObjectName(QString::fromUtf8("lineEditConfig"));

        gridLayout->addWidget(lineEditConfig, 7, 1, 1, 1);

        btnBrowseConfig = new QPushButton(groupBoxInput);
        btnBrowseConfig->setObjectName(QString::fromUtf8("btnBrowseConfig"));

        gridLayout->addWidget(btnBrowseConfig, 7, 2, 1, 1);

        labelOut = new QLabel(groupBoxInput);
        labelOut->setObjectName(QString::fromUtf8("labelOut"));

        gridLayout->addWidget(labelOut, 8, 0, 1, 1);

        horizontalLayoutOut = new QHBoxLayout();
        horizontalLayoutOut->setObjectName(QString::fromUtf8("horizontalLayoutOut"));
        labelOutBase = new QLabel(groupBoxInput);
        labelOutBase->setObjectName(QString::fromUtf8("labelOutBase"));

        horizontalLayoutOut->addWidget(labelOutBase);

        lineEditOut = new QLineEdit(groupBoxInput);
        lineEditOut->setObjectName(QString::fromUtf8("lineEditOut"));

        horizontalLayoutOut->addWidget(lineEditOut);


        gridLayout->addLayout(horizontalLayoutOut, 8, 1, 1, 2);


        verticalLayout->addWidget(groupBoxInput);

        groupBoxOptions = new QGroupBox(centralwidget);
        groupBoxOptions->setObjectName(QString::fromUtf8("groupBoxOptions"));
        horizontalLayout = new QHBoxLayout(groupBoxOptions);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        chkPan = new QCheckBox(groupBoxOptions);
        chkPan->setObjectName(QString::fromUtf8("chkPan"));
        chkPan->setChecked(true);

        horizontalLayout->addWidget(chkPan);

        chkWhiteModel = new QCheckBox(groupBoxOptions);
        chkWhiteModel->setObjectName(QString::fromUtf8("chkWhiteModel"));

        horizontalLayout->addWidget(chkWhiteModel);

        chkDisableFill = new QCheckBox(groupBoxOptions);
        chkDisableFill->setObjectName(QString::fromUtf8("chkDisableFill"));

        horizontalLayout->addWidget(chkDisableFill);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(groupBoxOptions);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnStart = new QPushButton(centralwidget);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));

        horizontalLayout_2->addWidget(btnStart);

        btnStop = new QPushButton(centralwidget);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));
        btnStop->setEnabled(false);

        horizontalLayout_2->addWidget(btnStop);


        verticalLayout->addLayout(horizontalLayout_2);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);
        progressBar->setTextVisible(true);
        progressBar->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(progressBar);

        groupBoxLog = new QGroupBox(centralwidget);
        groupBoxLog->setObjectName(QString::fromUtf8("groupBoxLog"));
        verticalLayoutLog = new QVBoxLayout(groupBoxLog);
        verticalLayoutLog->setObjectName(QString::fromUtf8("verticalLayoutLog"));
        textEditLog = new QTextEdit(groupBoxLog);
        textEditLog->setObjectName(QString::fromUtf8("textEditLog"));
        textEditLog->setReadOnly(true);
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(9);
        textEditLog->setFont(font);

        verticalLayoutLog->addWidget(textEditLog);


        verticalLayout->addWidget(groupBoxLog);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\344\270\255\347\205\244\350\210\252\346\265\2133D\350\241\227\351\201\223\351\207\215\345\273\272\345\256\242\346\210\267\347\253\257", nullptr));
        btnRestartDocker->setText(QCoreApplication::translate("MainWindow", "\351\207\215\345\220\257\345\256\271\345\231\250", nullptr));
#if QT_CONFIG(tooltip)
        btnRestartDocker->setToolTip(QCoreApplication::translate("MainWindow", "\351\207\215\345\220\257\345\220\216\345\217\260 Docker \345\256\271\345\231\250 (docker restart)", nullptr));
#endif // QT_CONFIG(tooltip)
        btnConfig->setText(QCoreApplication::translate("MainWindow", "\351\253\230\347\272\247\351\205\215\347\275\256 \360\237\233\210...", nullptr));
#if QT_CONFIG(tooltip)
        btnConfig->setToolTip(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271 config.yaml \351\253\230\347\272\247\347\256\227\346\263\225\345\217\202\346\225\260", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBoxDocker->setTitle(QCoreApplication::translate("MainWindow", "Docker \347\216\257\345\242\203\351\205\215\347\275\256", nullptr));
#if QT_CONFIG(tooltip)
        labelContainerName->setToolTip(QCoreApplication::translate("MainWindow", "\350\277\220\350\241\2143D\351\207\215\345\273\272\347\256\227\346\263\225\347\232\204Docker\345\256\271\345\231\250\345\220\215\347\247\260", nullptr));
#endif // QT_CONFIG(tooltip)
        labelContainerName->setText(QCoreApplication::translate("MainWindow", "\345\256\271\345\231\250\345\220\215\347\247\260 \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        lineEditContainerName->setToolTip(QCoreApplication::translate("MainWindow", "\350\277\220\350\241\2143D\351\207\215\345\273\272\347\256\227\346\263\225\347\232\204Docker\345\256\271\345\231\250\345\220\215\347\247\260", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEditContainerName->setText(QCoreApplication::translate("MainWindow", "zhongmei_3d", nullptr));
#if QT_CONFIG(tooltip)
        labelHostPath->setToolTip(QCoreApplication::translate("MainWindow", "\345\256\277\344\270\273\346\234\272\344\270\212\346\214\202\350\275\275\345\210\260\345\256\271\345\231\250\347\232\204\347\211\251\347\220\206\350\267\257\345\276\204\346\240\271\347\233\256\345\275\225\357\274\210\345\246\202 W:/zhongmei-3d-reconstruction\357\274\211\343\200\202\347\224\250\344\272\216\345\260\206 Windows \350\267\257\345\276\204\350\207\252\345\212\250\350\275\254\346\215\242\344\270\272\345\256\271\345\231\250\345\206\205\350\267\257\345\276\204", nullptr));
#endif // QT_CONFIG(tooltip)
        labelHostPath->setText(QCoreApplication::translate("MainWindow", "\345\256\277\344\270\273\346\234\272\346\214\202\350\275\275\350\267\257\345\276\204 \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        lineEditHostPath->setToolTip(QCoreApplication::translate("MainWindow", "\345\256\277\344\270\273\346\234\272\344\270\212\346\214\202\350\275\275\345\210\260\345\256\271\345\231\250\347\232\204\347\211\251\347\220\206\350\267\257\345\276\204\346\240\271\347\233\256\345\275\225\357\274\210\345\246\202 W:/zhongmei-3d-reconstruction\357\274\211\343\200\202\347\224\250\344\272\216\345\260\206 Windows \350\267\257\345\276\204\350\207\252\345\212\250\350\275\254\346\215\242\344\270\272\345\256\271\345\231\250\345\206\205\350\267\257\345\276\204", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEditHostPath->setText(QCoreApplication::translate("MainWindow", "W:/zhongmei-3d-reconstruction", nullptr));
#if QT_CONFIG(tooltip)
        labelContainerPath->setToolTip(QCoreApplication::translate("MainWindow", "Docker \345\256\271\345\231\250\345\206\205\345\257\271\345\272\224\347\232\204\346\214\202\350\275\275\347\202\271\350\267\257\345\276\204\357\274\210\351\200\232\345\270\270\344\270\272 /workspace\357\274\211", nullptr));
#endif // QT_CONFIG(tooltip)
        labelContainerPath->setText(QCoreApplication::translate("MainWindow", "\345\256\271\345\231\250\345\206\205\346\230\240\345\260\204\350\267\257\345\276\204 \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        lineEditContainerPath->setToolTip(QCoreApplication::translate("MainWindow", "Docker \345\256\271\345\231\250\345\206\205\345\257\271\345\272\224\347\232\204\346\214\202\350\275\275\347\202\271\350\267\257\345\276\204\357\274\210\351\200\232\345\270\270\344\270\272 /workspace\357\274\211", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEditContainerPath->setText(QCoreApplication::translate("MainWindow", "/workspace", nullptr));
        groupBoxInput->setTitle(QCoreApplication::translate("MainWindow", "\350\276\223\345\205\245/\350\276\223\345\207\272\351\205\215\347\275\256", nullptr));
#if QT_CONFIG(tooltip)
        labelLas->setToolTip(QCoreApplication::translate("MainWindow", "\347\202\271\344\272\221\346\226\207\344\273\266 .las\357\274\214\344\270\211\347\273\264\351\207\215\345\273\272\345\237\272\347\241\200\345\207\240\344\275\225\346\250\241\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
        labelLas->setText(QCoreApplication::translate("MainWindow", "LAS \347\202\271\344\272\221\346\226\207\344\273\266 \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        lineEditLas->setToolTip(QCoreApplication::translate("MainWindow", "\347\202\271\344\272\221\346\226\207\344\273\266 .las\357\274\214\344\270\211\347\273\264\351\207\215\345\273\272\345\237\272\347\241\200\345\207\240\344\275\225\346\250\241\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
        btnBrowseLas->setText(QCoreApplication::translate("MainWindow", "\346\265\217\350\247\210...", nullptr));
#if QT_CONFIG(tooltip)
        labelPos->setToolTip(QCoreApplication::translate("MainWindow", "\350\275\250\350\277\271\344\275\215\345\247\277\346\226\207\344\273\266 imgpost.txt (\345\244\232\347\233\256\346\250\241\345\274\217) \346\210\226 posl.txt (\345\205\250\346\231\257\346\250\241\345\274\217)", nullptr));
#endif // QT_CONFIG(tooltip)
        labelPos->setText(QCoreApplication::translate("MainWindow", "POS \350\275\250\350\277\271\346\226\207\344\273\266 \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        lineEditPos->setToolTip(QCoreApplication::translate("MainWindow", "\350\275\250\350\277\271\344\275\215\345\247\277\346\226\207\344\273\266 imgpost.txt (\345\244\232\347\233\256\346\250\241\345\274\217) \346\210\226 posl.txt (\345\205\250\346\231\257\346\250\241\345\274\217)", nullptr));
#endif // QT_CONFIG(tooltip)
        btnBrowsePos->setText(QCoreApplication::translate("MainWindow", "\346\265\217\350\247\210...", nullptr));
#if QT_CONFIG(tooltip)
        labelInspose->setToolTip(QCoreApplication::translate("MainWindow", "INSPose.dd \344\275\215\345\247\277\346\225\260\346\215\256\346\226\207\344\273\266\347\232\204\350\267\257\345\276\204 (\345\205\250\346\231\257\346\250\241\345\274\217\347\272\271\347\220\206\350\264\264\345\233\276\345\277\205\345\241\253)", nullptr));
#endif // QT_CONFIG(tooltip)
        labelInspose->setText(QCoreApplication::translate("MainWindow", "INSPose \346\226\207\344\273\266 \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        lineEditInspose->setToolTip(QCoreApplication::translate("MainWindow", "INSPose.dd \344\275\215\345\247\277\346\225\260\346\215\256\346\226\207\344\273\266\347\232\204\350\267\257\345\276\204 (\345\205\250\346\231\257\346\250\241\345\274\217\347\272\271\347\220\206\350\264\264\345\233\276\345\277\205\345\241\253)", nullptr));
#endif // QT_CONFIG(tooltip)
        btnBrowseInspose->setText(QCoreApplication::translate("MainWindow", "\346\265\217\350\247\210...", nullptr));
#if QT_CONFIG(tooltip)
        labelMetashape->setToolTip(QCoreApplication::translate("MainWindow", "Metashape.txt \347\233\270\346\234\272\344\275\215\347\275\256\346\226\207\344\273\266\347\232\204\350\267\257\345\276\204 (\345\205\250\346\231\257\346\250\241\345\274\217\347\272\271\347\220\206\350\264\264\345\233\276\345\277\205\345\241\253)", nullptr));
#endif // QT_CONFIG(tooltip)
        labelMetashape->setText(QCoreApplication::translate("MainWindow", "Metashape \346\226\207\344\273\266 \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        lineEditMetashape->setToolTip(QCoreApplication::translate("MainWindow", "Metashape.txt \347\233\270\346\234\272\344\275\215\347\275\256\346\226\207\344\273\266\347\232\204\350\267\257\345\276\204 (\345\205\250\346\231\257\346\250\241\345\274\217\347\272\271\347\220\206\350\264\264\345\233\276\345\277\205\345\241\253)", nullptr));
#endif // QT_CONFIG(tooltip)
        btnBrowseMetashape->setText(QCoreApplication::translate("MainWindow", "\346\265\217\350\247\210...", nullptr));
#if QT_CONFIG(tooltip)
        labelImageDir->setToolTip(QCoreApplication::translate("MainWindow", "\345\255\230\346\224\276\345\205\250\346\231\257\345\233\276\345\203\217\347\232\204\347\233\256\345\275\225\350\267\257\345\276\204 (\345\205\250\346\231\257\346\250\241\345\274\217\347\272\271\347\220\206\350\264\264\345\233\276\345\277\205\345\241\253)", nullptr));
#endif // QT_CONFIG(tooltip)
        labelImageDir->setText(QCoreApplication::translate("MainWindow", "\345\205\250\346\231\257\345\233\276\345\203\217\347\233\256\345\275\225 \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        lineEditImageDir->setToolTip(QCoreApplication::translate("MainWindow", "\345\255\230\346\224\276\345\205\250\346\231\257\345\233\276\345\203\217\347\232\204\347\233\256\345\275\225\350\267\257\345\276\204 (\345\205\250\346\231\257\346\250\241\345\274\217\347\272\271\347\220\206\350\264\264\345\233\276\345\277\205\345\241\253)", nullptr));
#endif // QT_CONFIG(tooltip)
        btnBrowseImageDir->setText(QCoreApplication::translate("MainWindow", "\346\265\217\350\247\210...", nullptr));
#if QT_CONFIG(tooltip)
        labelMask->setToolTip(QCoreApplication::translate("MainWindow", "mask.png \345\272\225\351\203\250\351\201\256\347\275\251\345\233\276\347\232\204\350\267\257\345\276\204 (\345\205\250\346\231\257\346\250\241\345\274\217\345\217\257\351\200\211)", nullptr));
#endif // QT_CONFIG(tooltip)
        labelMask->setText(QCoreApplication::translate("MainWindow", "Mask \351\201\256\347\275\251\345\233\276 \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        lineEditMask->setToolTip(QCoreApplication::translate("MainWindow", "mask.png \345\272\225\351\203\250\351\201\256\347\275\251\345\233\276\347\232\204\350\267\257\345\276\204 (\345\205\250\346\231\257\346\250\241\345\274\217\345\217\257\351\200\211)", nullptr));
#endif // QT_CONFIG(tooltip)
        btnBrowseMask->setText(QCoreApplication::translate("MainWindow", "\346\265\217\350\247\210...", nullptr));
#if QT_CONFIG(tooltip)
        labelIni->setToolTip(QCoreApplication::translate("MainWindow", "\347\233\270\346\234\272\346\240\207\345\256\232\346\226\207\344\273\266 .ini\357\274\214\350\257\273\345\217\226\345\244\232\347\233\256\347\233\270\346\234\272\347\232\204\345\206\205\345\217\202\345\217\212\346\235\206\350\207\202\345\244\226\345\217\202 (\344\273\205\345\244\232\347\233\256\346\250\241\345\274\217\351\234\200\346\217\220\344\276\233)", nullptr));
#endif // QT_CONFIG(tooltip)
        labelIni->setText(QCoreApplication::translate("MainWindow", "\347\233\270\346\234\272\346\240\207\345\256\232 \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        lineEditIni->setToolTip(QCoreApplication::translate("MainWindow", "\347\233\270\346\234\272\346\240\207\345\256\232\346\226\207\344\273\266 .ini\357\274\214\350\257\273\345\217\226\345\244\232\347\233\256\347\233\270\346\234\272\347\232\204\345\206\205\345\217\202\345\217\212\346\235\206\350\207\202\345\244\226\345\217\202 (\344\273\205\345\244\232\347\233\256\346\250\241\345\274\217\351\234\200\346\217\220\344\276\233)", nullptr));
#endif // QT_CONFIG(tooltip)
        btnBrowseIni->setText(QCoreApplication::translate("MainWindow", "\346\265\217\350\247\210...", nullptr));
#if QT_CONFIG(tooltip)
        labelConfig->setToolTip(QCoreApplication::translate("MainWindow", "\347\233\270\346\234\272\351\205\215\347\275\256 JSON \346\226\207\344\273\266 .json\357\274\214\347\273\221\345\256\232\345\220\204\347\233\270\346\234\272\347\232\204\345\233\276\345\203\217\347\233\256\345\275\225\344\270\216\344\275\215\345\247\277\350\256\260\345\275\225 (\344\273\205\345\244\232\347\233\256\346\250\241\345\274\217\351\234\200\346\217\220\344\276\233)\343\200\202\n"
"\347\202\271\345\207\273\345\217\263\344\276\247\343\200\220\345\257\274\345\207\272\346\250\241\346\235\277\343\200\221\346\214\211\351\222\256\345\217\257\347\224\237\346\210\220\344\270\200\344\273\275\346\240\207\345\207\206\347\232\204\351\205\215\347\275\256\346\226\207\344\273\266\345\217\212\345\255\227\346\256\265\350\257\264\346\230\216\343\200\202", nullptr));
#endif // QT_CONFIG(tooltip)
        labelConfig->setText(QCoreApplication::translate("MainWindow", "\347\233\270\346\234\272\351\205\215\347\275\256 \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        btnExportConfigTemplate->setToolTip(QCoreApplication::translate("MainWindow", "\345\257\274\345\207\272\347\233\270\346\234\272\351\205\215\347\275\256\347\232\204\347\244\272\344\276\213\346\250\241\346\235\277 JSON \346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        btnExportConfigTemplate->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\207\272\346\250\241\346\235\277", nullptr));
#if QT_CONFIG(tooltip)
        lineEditConfig->setToolTip(QCoreApplication::translate("MainWindow", "\347\233\270\346\234\272\351\205\215\347\275\256 JSON \346\226\207\344\273\266 .json\357\274\214\347\273\221\345\256\232\345\220\204\347\233\270\346\234\272\347\232\204\345\233\276\345\203\217\347\233\256\345\275\225\344\270\216\344\275\215\345\247\277\350\256\260\345\275\225 (\344\273\205\345\244\232\347\233\256\346\250\241\345\274\217\351\234\200\346\217\220\344\276\233)\343\200\202\n"
"\347\202\271\345\207\273\345\267\246\344\276\247\343\200\220\345\257\274\345\207\272\346\250\241\346\235\277\343\200\221\346\214\211\351\222\256\345\217\257\347\224\237\346\210\220\344\270\200\344\273\275\346\240\207\345\207\206\347\232\204\351\205\215\347\275\256\346\226\207\344\273\266\345\217\212\345\255\227\346\256\265\350\257\264\346\230\216\343\200\202", nullptr));
#endif // QT_CONFIG(tooltip)
        btnBrowseConfig->setText(QCoreApplication::translate("MainWindow", "\346\265\217\350\247\210...", nullptr));
#if QT_CONFIG(tooltip)
        labelOut->setToolTip(QCoreApplication::translate("MainWindow", "\345\237\272\344\272\216\345\256\277\344\270\273\346\234\272\346\214\202\350\275\275\350\267\257\345\276\204\347\232\204\347\233\270\345\257\271\350\276\223\345\207\272\345\255\220\347\233\256\345\275\225\343\200\202\345\256\236\351\231\205\345\260\206\344\277\235\345\255\230\345\234\250: \346\214\202\350\275\275\347\233\256\345\275\225/\350\276\223\345\207\272\345\255\220\347\233\256\345\275\225 \344\270\213", nullptr));
#endif // QT_CONFIG(tooltip)
        labelOut->setText(QCoreApplication::translate("MainWindow", "\350\276\223\345\207\272\347\233\256\345\275\225 \360\237\233\210:", nullptr));
        labelOutBase->setText(QCoreApplication::translate("MainWindow", "W:/zhongmei-3d-reconstruction/", nullptr));
#if QT_CONFIG(tooltip)
        lineEditOut->setToolTip(QCoreApplication::translate("MainWindow", "\345\237\272\344\272\216\345\256\277\344\270\273\346\234\272\346\214\202\350\275\275\350\267\257\345\276\204\347\232\204\347\233\270\345\257\271\350\276\223\345\207\272\345\255\220\347\233\256\345\275\225\343\200\202\344\276\213\345\246\202\350\276\223\345\205\245 output/test\357\274\214\345\256\236\351\231\205\345\260\206\344\277\235\345\255\230\345\234\250 \345\256\277\344\270\273\346\234\272\346\214\202\350\275\275\350\267\257\345\276\204/output/test \344\270\213", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEditOut->setText(QCoreApplication::translate("MainWindow", "output", nullptr));
        lineEditOut->setPlaceholderText(QCoreApplication::translate("MainWindow", "\344\276\213\345\246\202: output/task1 (\345\260\206\350\207\252\345\212\250\345\273\272\345\234\250\346\214\202\350\275\275\347\233\256\345\275\225\344\270\213)", nullptr));
        groupBoxOptions->setTitle(QCoreApplication::translate("MainWindow", "\347\256\227\346\263\225\345\217\202\346\225\260", nullptr));
#if QT_CONFIG(tooltip)
        chkPan->setToolTip(QCoreApplication::translate("MainWindow", "\346\240\270\345\277\203\346\250\241\345\274\217\345\274\200\345\205\263\343\200\202\345\213\276\351\200\211\344\270\272\345\205\250\346\231\257\346\250\241\345\274\217\357\274\214\344\270\215\345\213\276\351\200\211\345\274\200\345\220\257\345\244\232\347\233\256\345\256\232\345\220\221\347\233\270\346\234\272\346\250\241\345\274\217", nullptr));
#endif // QT_CONFIG(tooltip)
        chkPan->setText(QCoreApplication::translate("MainWindow", "\345\205\250\346\231\257\346\250\241\345\274\217 \360\237\233\210", nullptr));
#if QT_CONFIG(tooltip)
        chkWhiteModel->setToolTip(QCoreApplication::translate("MainWindow", "\347\231\275\346\250\241\346\250\241\345\274\217\357\274\214\350\267\263\350\277\207\347\272\271\347\220\206\350\264\264\345\233\276\346\255\245\351\252\244", nullptr));
#endif // QT_CONFIG(tooltip)
        chkWhiteModel->setText(QCoreApplication::translate("MainWindow", "\347\231\275\346\250\241\346\250\241\345\274\217 \360\237\233\210", nullptr));
#if QT_CONFIG(tooltip)
        chkDisableFill->setToolTip(QCoreApplication::translate("MainWindow", "\357\274\210\345\217\257\351\200\211\357\274\211\345\205\263\351\227\255\347\202\271\344\272\221\345\241\253\350\241\245\344\270\216\350\243\202\347\274\235\344\277\256\345\244\215\343\200\202\345\275\223\346\272\220\347\202\271\344\272\221\345\255\230\345\234\250\345\244\247\351\207\217\350\264\264\345\234\260\345\231\252\345\243\260\346\227\266\345\273\272\350\256\256\345\213\276\351\200\211\357\274\214\351\230\262\346\255\242\347\224\237\346\210\220\342\200\234\344\274\252\350\267\257\351\235\242\342\200\235\345\257\274\350\207\264\347\272\271\347\220\206\351\224\231\344\271\261", nullptr));
#endif // QT_CONFIG(tooltip)
        chkDisableFill->setText(QCoreApplication::translate("MainWindow", "\347\246\201\347\224\250\350\267\257\351\235\242\350\241\245\346\264\236 \360\237\233\210", nullptr));
        btnStart->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\351\207\215\345\273\272", nullptr));
        btnStop->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242/\347\273\210\346\255\242", nullptr));
        groupBoxLog->setTitle(QCoreApplication::translate("MainWindow", "Docker \350\277\220\350\241\214\346\227\245\345\277\227", nullptr));
        textEditLog->setStyleSheet(QCoreApplication::translate("MainWindow", "QTextEdit { background-color: #1E1E1E; color: #D4D4D4; }", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

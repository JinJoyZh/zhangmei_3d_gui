/********************************************************************************
** Form generated from reading UI file 'configdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGDIALOG_H
#define UI_CONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigDialog
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBoxDebug;
    QFormLayout *formLayoutDebug;
    QLabel *label_debug;
    QCheckBox *chk_debug_log_enabled;
    QGroupBox *groupBoxMesh;
    QFormLayout *formLayoutMesh;
    QLabel *label_mesh1;
    QDoubleSpinBox *spin_sky_mesh_height_threshold;
    QLabel *label_mesh2;
    QDoubleSpinBox *spin_camera_height;
    QLabel *label_mesh3;
    QDoubleSpinBox *spin_sky_mesh_core_tolerance;
    QLabel *label_mesh4;
    QDoubleSpinBox *spin_sky_mesh_relaxed_tolerance;
    QLabel *label_mesh5;
    QDoubleSpinBox *spin_sky_mesh_max_edge_length;
    QLabel *label_mesh6;
    QSpinBox *spin_poisson_depth;
    QLabel *label_mesh7;
    QDoubleSpinBox *spin_poisson_density_quantile;
    QGroupBox *groupBoxPre;
    QFormLayout *formLayoutPre;
    QLabel *label_pre1;
    QSpinBox *spin_auto_split_max_size_mb;
    QLabel *label_pre2;
    QSpinBox *spin_camera_count;
    QGroupBox *groupBoxTex;
    QFormLayout *formLayoutTex;
    QLabel *label_tex1;
    QCheckBox *chk_enable_point_cloud_baking;
    QLabel *label_tex2;
    QDoubleSpinBox *spin_mask_scale_width;
    QLabel *label_tex3;
    QDoubleSpinBox *spin_mask_scale_length;
    QLabel *label_tex4;
    QDoubleSpinBox *spin_max_baseline_warning;
    QLabel *label_tex5;
    QDoubleSpinBox *spin_min_grazing_angle_warning;
    QGroupBox *groupBoxSign;
    QFormLayout *formLayoutSign;
    QLabel *label_sign1;
    QCheckBox *chk_sign_enabled;
    QLabel *label_sign2;
    QDoubleSpinBox *spin_sign_max_distance_to_cam;
    QLabel *label_sign3;
    QDoubleSpinBox *spin_sign_min_z_height;
    QLabel *label_sign4;
    QDoubleSpinBox *spin_sign_clustering_distance;
    QLabel *label_sign5;
    QDoubleSpinBox *spin_sign_bbox_crop_scale;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnRestoreDefault;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnCancel;

    void setupUi(QDialog *ConfigDialog)
    {
        if (ConfigDialog->objectName().isEmpty())
            ConfigDialog->setObjectName(QString::fromUtf8("ConfigDialog"));
        ConfigDialog->resize(700, 600);
        verticalLayout = new QVBoxLayout(ConfigDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(ConfigDialog);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 676, 750));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBoxDebug = new QGroupBox(scrollAreaWidgetContents);
        groupBoxDebug->setObjectName(QString::fromUtf8("groupBoxDebug"));
        formLayoutDebug = new QFormLayout(groupBoxDebug);
        formLayoutDebug->setObjectName(QString::fromUtf8("formLayoutDebug"));
        label_debug = new QLabel(groupBoxDebug);
        label_debug->setObjectName(QString::fromUtf8("label_debug"));

        formLayoutDebug->setWidget(0, QFormLayout::LabelRole, label_debug);

        chk_debug_log_enabled = new QCheckBox(groupBoxDebug);
        chk_debug_log_enabled->setObjectName(QString::fromUtf8("chk_debug_log_enabled"));

        formLayoutDebug->setWidget(0, QFormLayout::FieldRole, chk_debug_log_enabled);


        verticalLayout_2->addWidget(groupBoxDebug);

        groupBoxMesh = new QGroupBox(scrollAreaWidgetContents);
        groupBoxMesh->setObjectName(QString::fromUtf8("groupBoxMesh"));
        formLayoutMesh = new QFormLayout(groupBoxMesh);
        formLayoutMesh->setObjectName(QString::fromUtf8("formLayoutMesh"));
        label_mesh1 = new QLabel(groupBoxMesh);
        label_mesh1->setObjectName(QString::fromUtf8("label_mesh1"));

        formLayoutMesh->setWidget(0, QFormLayout::LabelRole, label_mesh1);

        spin_sky_mesh_height_threshold = new QDoubleSpinBox(groupBoxMesh);
        spin_sky_mesh_height_threshold->setObjectName(QString::fromUtf8("spin_sky_mesh_height_threshold"));
        spin_sky_mesh_height_threshold->setDecimals(2);
        spin_sky_mesh_height_threshold->setSingleStep(0.100000000000000);

        formLayoutMesh->setWidget(0, QFormLayout::FieldRole, spin_sky_mesh_height_threshold);

        label_mesh2 = new QLabel(groupBoxMesh);
        label_mesh2->setObjectName(QString::fromUtf8("label_mesh2"));

        formLayoutMesh->setWidget(1, QFormLayout::LabelRole, label_mesh2);

        spin_camera_height = new QDoubleSpinBox(groupBoxMesh);
        spin_camera_height->setObjectName(QString::fromUtf8("spin_camera_height"));
        spin_camera_height->setDecimals(2);
        spin_camera_height->setSingleStep(0.100000000000000);

        formLayoutMesh->setWidget(1, QFormLayout::FieldRole, spin_camera_height);

        label_mesh3 = new QLabel(groupBoxMesh);
        label_mesh3->setObjectName(QString::fromUtf8("label_mesh3"));

        formLayoutMesh->setWidget(2, QFormLayout::LabelRole, label_mesh3);

        spin_sky_mesh_core_tolerance = new QDoubleSpinBox(groupBoxMesh);
        spin_sky_mesh_core_tolerance->setObjectName(QString::fromUtf8("spin_sky_mesh_core_tolerance"));
        spin_sky_mesh_core_tolerance->setDecimals(3);
        spin_sky_mesh_core_tolerance->setSingleStep(0.010000000000000);

        formLayoutMesh->setWidget(2, QFormLayout::FieldRole, spin_sky_mesh_core_tolerance);

        label_mesh4 = new QLabel(groupBoxMesh);
        label_mesh4->setObjectName(QString::fromUtf8("label_mesh4"));

        formLayoutMesh->setWidget(3, QFormLayout::LabelRole, label_mesh4);

        spin_sky_mesh_relaxed_tolerance = new QDoubleSpinBox(groupBoxMesh);
        spin_sky_mesh_relaxed_tolerance->setObjectName(QString::fromUtf8("spin_sky_mesh_relaxed_tolerance"));
        spin_sky_mesh_relaxed_tolerance->setDecimals(3);
        spin_sky_mesh_relaxed_tolerance->setSingleStep(0.010000000000000);

        formLayoutMesh->setWidget(3, QFormLayout::FieldRole, spin_sky_mesh_relaxed_tolerance);

        label_mesh5 = new QLabel(groupBoxMesh);
        label_mesh5->setObjectName(QString::fromUtf8("label_mesh5"));

        formLayoutMesh->setWidget(4, QFormLayout::LabelRole, label_mesh5);

        spin_sky_mesh_max_edge_length = new QDoubleSpinBox(groupBoxMesh);
        spin_sky_mesh_max_edge_length->setObjectName(QString::fromUtf8("spin_sky_mesh_max_edge_length"));
        spin_sky_mesh_max_edge_length->setDecimals(3);
        spin_sky_mesh_max_edge_length->setSingleStep(0.050000000000000);

        formLayoutMesh->setWidget(4, QFormLayout::FieldRole, spin_sky_mesh_max_edge_length);

        label_mesh6 = new QLabel(groupBoxMesh);
        label_mesh6->setObjectName(QString::fromUtf8("label_mesh6"));

        formLayoutMesh->setWidget(5, QFormLayout::LabelRole, label_mesh6);

        spin_poisson_depth = new QSpinBox(groupBoxMesh);
        spin_poisson_depth->setObjectName(QString::fromUtf8("spin_poisson_depth"));
        spin_poisson_depth->setMinimum(5);
        spin_poisson_depth->setMaximum(15);

        formLayoutMesh->setWidget(5, QFormLayout::FieldRole, spin_poisson_depth);

        label_mesh7 = new QLabel(groupBoxMesh);
        label_mesh7->setObjectName(QString::fromUtf8("label_mesh7"));

        formLayoutMesh->setWidget(6, QFormLayout::LabelRole, label_mesh7);

        spin_poisson_density_quantile = new QDoubleSpinBox(groupBoxMesh);
        spin_poisson_density_quantile->setObjectName(QString::fromUtf8("spin_poisson_density_quantile"));
        spin_poisson_density_quantile->setDecimals(4);
        spin_poisson_density_quantile->setSingleStep(0.001000000000000);

        formLayoutMesh->setWidget(6, QFormLayout::FieldRole, spin_poisson_density_quantile);


        verticalLayout_2->addWidget(groupBoxMesh);

        groupBoxPre = new QGroupBox(scrollAreaWidgetContents);
        groupBoxPre->setObjectName(QString::fromUtf8("groupBoxPre"));
        formLayoutPre = new QFormLayout(groupBoxPre);
        formLayoutPre->setObjectName(QString::fromUtf8("formLayoutPre"));
        label_pre1 = new QLabel(groupBoxPre);
        label_pre1->setObjectName(QString::fromUtf8("label_pre1"));

        formLayoutPre->setWidget(0, QFormLayout::LabelRole, label_pre1);

        spin_auto_split_max_size_mb = new QSpinBox(groupBoxPre);
        spin_auto_split_max_size_mb->setObjectName(QString::fromUtf8("spin_auto_split_max_size_mb"));
        spin_auto_split_max_size_mb->setMaximum(10000);
        spin_auto_split_max_size_mb->setSingleStep(100);

        formLayoutPre->setWidget(0, QFormLayout::FieldRole, spin_auto_split_max_size_mb);

        label_pre2 = new QLabel(groupBoxPre);
        label_pre2->setObjectName(QString::fromUtf8("label_pre2"));

        formLayoutPre->setWidget(1, QFormLayout::LabelRole, label_pre2);

        spin_camera_count = new QSpinBox(groupBoxPre);
        spin_camera_count->setObjectName(QString::fromUtf8("spin_camera_count"));
        spin_camera_count->setMinimum(1);
        spin_camera_count->setMaximum(10);

        formLayoutPre->setWidget(1, QFormLayout::FieldRole, spin_camera_count);


        verticalLayout_2->addWidget(groupBoxPre);

        groupBoxTex = new QGroupBox(scrollAreaWidgetContents);
        groupBoxTex->setObjectName(QString::fromUtf8("groupBoxTex"));
        formLayoutTex = new QFormLayout(groupBoxTex);
        formLayoutTex->setObjectName(QString::fromUtf8("formLayoutTex"));
        label_tex1 = new QLabel(groupBoxTex);
        label_tex1->setObjectName(QString::fromUtf8("label_tex1"));

        formLayoutTex->setWidget(0, QFormLayout::LabelRole, label_tex1);

        chk_enable_point_cloud_baking = new QCheckBox(groupBoxTex);
        chk_enable_point_cloud_baking->setObjectName(QString::fromUtf8("chk_enable_point_cloud_baking"));

        formLayoutTex->setWidget(0, QFormLayout::FieldRole, chk_enable_point_cloud_baking);

        label_tex2 = new QLabel(groupBoxTex);
        label_tex2->setObjectName(QString::fromUtf8("label_tex2"));

        formLayoutTex->setWidget(1, QFormLayout::LabelRole, label_tex2);

        spin_mask_scale_width = new QDoubleSpinBox(groupBoxTex);
        spin_mask_scale_width->setObjectName(QString::fromUtf8("spin_mask_scale_width"));
        spin_mask_scale_width->setDecimals(2);
        spin_mask_scale_width->setSingleStep(0.100000000000000);

        formLayoutTex->setWidget(1, QFormLayout::FieldRole, spin_mask_scale_width);

        label_tex3 = new QLabel(groupBoxTex);
        label_tex3->setObjectName(QString::fromUtf8("label_tex3"));

        formLayoutTex->setWidget(2, QFormLayout::LabelRole, label_tex3);

        spin_mask_scale_length = new QDoubleSpinBox(groupBoxTex);
        spin_mask_scale_length->setObjectName(QString::fromUtf8("spin_mask_scale_length"));
        spin_mask_scale_length->setDecimals(2);
        spin_mask_scale_length->setSingleStep(0.100000000000000);

        formLayoutTex->setWidget(2, QFormLayout::FieldRole, spin_mask_scale_length);

        label_tex4 = new QLabel(groupBoxTex);
        label_tex4->setObjectName(QString::fromUtf8("label_tex4"));

        formLayoutTex->setWidget(3, QFormLayout::LabelRole, label_tex4);

        spin_max_baseline_warning = new QDoubleSpinBox(groupBoxTex);
        spin_max_baseline_warning->setObjectName(QString::fromUtf8("spin_max_baseline_warning"));
        spin_max_baseline_warning->setDecimals(2);
        spin_max_baseline_warning->setSingleStep(0.500000000000000);

        formLayoutTex->setWidget(3, QFormLayout::FieldRole, spin_max_baseline_warning);

        label_tex5 = new QLabel(groupBoxTex);
        label_tex5->setObjectName(QString::fromUtf8("label_tex5"));

        formLayoutTex->setWidget(4, QFormLayout::LabelRole, label_tex5);

        spin_min_grazing_angle_warning = new QDoubleSpinBox(groupBoxTex);
        spin_min_grazing_angle_warning->setObjectName(QString::fromUtf8("spin_min_grazing_angle_warning"));
        spin_min_grazing_angle_warning->setDecimals(1);
        spin_min_grazing_angle_warning->setSingleStep(1.000000000000000);

        formLayoutTex->setWidget(4, QFormLayout::FieldRole, spin_min_grazing_angle_warning);


        verticalLayout_2->addWidget(groupBoxTex);

        groupBoxSign = new QGroupBox(scrollAreaWidgetContents);
        groupBoxSign->setObjectName(QString::fromUtf8("groupBoxSign"));
        formLayoutSign = new QFormLayout(groupBoxSign);
        formLayoutSign->setObjectName(QString::fromUtf8("formLayoutSign"));
        label_sign1 = new QLabel(groupBoxSign);
        label_sign1->setObjectName(QString::fromUtf8("label_sign1"));

        formLayoutSign->setWidget(0, QFormLayout::LabelRole, label_sign1);

        chk_sign_enabled = new QCheckBox(groupBoxSign);
        chk_sign_enabled->setObjectName(QString::fromUtf8("chk_sign_enabled"));

        formLayoutSign->setWidget(0, QFormLayout::FieldRole, chk_sign_enabled);

        label_sign2 = new QLabel(groupBoxSign);
        label_sign2->setObjectName(QString::fromUtf8("label_sign2"));

        formLayoutSign->setWidget(1, QFormLayout::LabelRole, label_sign2);

        spin_sign_max_distance_to_cam = new QDoubleSpinBox(groupBoxSign);
        spin_sign_max_distance_to_cam->setObjectName(QString::fromUtf8("spin_sign_max_distance_to_cam"));
        spin_sign_max_distance_to_cam->setDecimals(2);
        spin_sign_max_distance_to_cam->setSingleStep(1.000000000000000);

        formLayoutSign->setWidget(1, QFormLayout::FieldRole, spin_sign_max_distance_to_cam);

        label_sign3 = new QLabel(groupBoxSign);
        label_sign3->setObjectName(QString::fromUtf8("label_sign3"));

        formLayoutSign->setWidget(2, QFormLayout::LabelRole, label_sign3);

        spin_sign_min_z_height = new QDoubleSpinBox(groupBoxSign);
        spin_sign_min_z_height->setObjectName(QString::fromUtf8("spin_sign_min_z_height"));
        spin_sign_min_z_height->setDecimals(2);
        spin_sign_min_z_height->setSingleStep(0.100000000000000);

        formLayoutSign->setWidget(2, QFormLayout::FieldRole, spin_sign_min_z_height);

        label_sign4 = new QLabel(groupBoxSign);
        label_sign4->setObjectName(QString::fromUtf8("label_sign4"));

        formLayoutSign->setWidget(3, QFormLayout::LabelRole, label_sign4);

        spin_sign_clustering_distance = new QDoubleSpinBox(groupBoxSign);
        spin_sign_clustering_distance->setObjectName(QString::fromUtf8("spin_sign_clustering_distance"));
        spin_sign_clustering_distance->setDecimals(2);
        spin_sign_clustering_distance->setSingleStep(0.100000000000000);

        formLayoutSign->setWidget(3, QFormLayout::FieldRole, spin_sign_clustering_distance);

        label_sign5 = new QLabel(groupBoxSign);
        label_sign5->setObjectName(QString::fromUtf8("label_sign5"));

        formLayoutSign->setWidget(4, QFormLayout::LabelRole, label_sign5);

        spin_sign_bbox_crop_scale = new QDoubleSpinBox(groupBoxSign);
        spin_sign_bbox_crop_scale->setObjectName(QString::fromUtf8("spin_sign_bbox_crop_scale"));
        spin_sign_bbox_crop_scale->setDecimals(2);
        spin_sign_bbox_crop_scale->setSingleStep(0.100000000000000);

        formLayoutSign->setWidget(4, QFormLayout::FieldRole, spin_sign_bbox_crop_scale);


        verticalLayout_2->addWidget(groupBoxSign);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnRestoreDefault = new QPushButton(ConfigDialog);
        btnRestoreDefault->setObjectName(QString::fromUtf8("btnRestoreDefault"));

        horizontalLayout->addWidget(btnRestoreDefault);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSave = new QPushButton(ConfigDialog);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(ConfigDialog);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ConfigDialog);

        QMetaObject::connectSlotsByName(ConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigDialog)
    {
        ConfigDialog->setWindowTitle(QCoreApplication::translate("ConfigDialog", "\351\253\230\347\272\247\351\205\215\347\275\256 (config.yaml)", nullptr));
        groupBoxDebug->setTitle(QCoreApplication::translate("ConfigDialog", "\345\237\272\347\241\200\344\270\216\350\260\203\350\257\225", nullptr));
        label_debug->setText(QCoreApplication::translate("ConfigDialog", "\350\276\223\345\207\272\350\260\203\350\257\225\346\227\245\345\277\227 \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        label_debug->setToolTip(QCoreApplication::translate("ConfigDialog", "\350\260\203\350\257\225\346\227\245\345\277\227\345\274\200\345\205\263\357\274\232\n"
"\346\230\257\345\220\246\350\276\223\345\207\272\351\242\235\345\244\226\347\232\204\344\270\255\351\227\264\350\260\203\350\257\225\344\277\241\346\201\257\357\274\214\345\246\202\345\260\206\346\243\200\346\265\213\344\270\216\345\210\206\345\211\262\347\232\204\344\270\255\351\227\264\347\273\223\346\236\234\345\233\276\345\203\217\357\274\210\345\214\205\345\220\253\346\243\200\346\265\213\346\241\206\345\222\214 SAM \346\216\251\350\206\234\357\274\211\n"
"\344\277\235\345\255\230\345\210\260\346\257\217\344\270\252\345\210\206\346\256\265\347\232\204 images \346\226\207\344\273\266\345\244\271\344\270\213\344\273\245\344\276\233\350\260\203\350\257\225\343\200\202", nullptr));
#endif // QT_CONFIG(tooltip)
        chk_debug_log_enabled->setText(QCoreApplication::translate("ConfigDialog", "\345\274\200\345\220\257", nullptr));
        groupBoxMesh->setTitle(QCoreApplication::translate("ConfigDialog", "\347\275\221\346\240\274\350\277\207\346\273\244", nullptr));
        label_mesh1->setText(QCoreApplication::translate("ConfigDialog", "\345\244\251\347\251\272\351\243\236\351\235\242\350\277\207\346\273\244\351\253\230\345\272\246\351\230\210\345\200\274 \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        label_mesh1->setToolTip(QCoreApplication::translate("ConfigDialog", "\350\267\235\347\246\273\345\234\260\351\235\242\345\244\232\351\253\230\344\273\245\344\270\212\347\232\204\347\275\221\346\240\274\345\260\206\350\277\233\350\241\214\347\202\271\344\272\221\345\210\260\347\275\221\346\240\274\347\232\204\350\267\235\347\246\273\351\252\214\350\257\201\357\274\214\345\211\224\351\231\244\342\200\234\345\244\251\347\251\272\351\243\236\351\235\242\342\200\235", nullptr));
#endif // QT_CONFIG(tooltip)
        label_mesh2->setText(QCoreApplication::translate("ConfigDialog", "\347\233\270\346\234\272\345\244\247\346\246\202\351\253\230\345\272\246 (\347\261\263) \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        label_mesh2->setToolTip(QCoreApplication::translate("ConfigDialog", "\350\275\250\350\277\271\347\202\271\357\274\210\347\233\270\346\234\272/\350\275\246\351\241\266\357\274\211\350\267\235\347\246\273\345\234\260\351\235\242\347\232\204\345\244\247\346\246\202\351\253\230\345\272\246 (\347\261\263)", nullptr));
#endif // QT_CONFIG(tooltip)
        label_mesh3->setText(QCoreApplication::translate("ConfigDialog", "\346\240\270\345\277\203\345\256\211\345\205\250\347\202\271\350\267\235\347\246\273\345\256\271\345\267\256 \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        label_mesh3->setToolTip(QCoreApplication::translate("ConfigDialog", "\346\240\270\345\277\203\345\256\211\345\205\250\347\202\271\350\267\235\347\246\273\345\256\271\345\267\256\357\274\232\350\267\235\347\246\273\347\202\271\344\272\221\345\260\217\344\272\216\346\255\244\345\200\274\347\232\204\351\241\266\347\202\271\350\242\253\350\256\244\344\270\272\346\230\257\347\273\235\345\257\271\345\256\211\345\205\250\347\232\204\342\200\234\346\240\270\345\277\203\347\202\271\342\200\235 (\345\216\237 0.05m)", nullptr));
#endif // QT_CONFIG(tooltip)
        label_mesh4->setText(QCoreApplication::translate("ConfigDialog", "\346\224\276\345\256\275\350\267\235\347\246\273\345\256\271\345\267\256 \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        label_mesh4->setToolTip(QCoreApplication::translate("ConfigDialog", "\346\224\276\345\256\275\350\267\235\347\246\273\345\256\271\345\267\256\357\274\232\350\267\235\347\246\273\347\202\271\344\272\221\345\234\250\346\255\244\345\200\274\350\214\203\345\233\264\345\206\205\357\274\214\344\270\224\344\270\216\342\200\234\346\240\270\345\277\203\347\202\271\342\200\235\347\233\270\350\277\236\347\232\204\351\241\266\347\202\271\357\274\214\345\260\206\350\242\253\344\275\234\344\270\272\345\220\210\346\263\225\350\276\271\347\274\230\344\277\235\347\225\231", nullptr));
#endif // QT_CONFIG(tooltip)
        label_mesh5->setText(QCoreApplication::translate("ConfigDialog", "\350\277\236\351\200\232\350\276\271\351\225\277\351\230\210\345\200\274 \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        label_mesh5->setToolTip(QCoreApplication::translate("ConfigDialog", "\350\277\236\351\200\232\350\276\271\351\225\277\351\230\210\345\200\274\357\274\232\345\217\252\346\234\211\345\275\223\351\241\266\347\202\271\344\270\216\346\240\270\345\277\203\347\202\271\344\271\213\351\227\264\347\232\204\350\276\271\351\225\277\345\260\217\344\272\216\346\255\244\345\200\274\346\227\266\357\274\214\346\211\215\350\256\244\344\270\272\345\256\203\344\273\254\346\230\257\342\200\234\347\264\247\345\257\206\350\277\236\346\216\245\342\200\235\347\232\204\357\274\214\351\230\262\346\255\242\351\243\236\351\235\242\350\242\253\346\204\217\345\244\226\346\204\237\346\237\223\344\277\235\347\225\231", nullptr));
#endif // QT_CONFIG(tooltip)
        label_mesh6->setText(QCoreApplication::translate("ConfigDialog", "\346\263\212\346\235\276\351\207\215\345\273\272\346\267\261\345\272\246 \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        label_mesh6->setToolTip(QCoreApplication::translate("ConfigDialog", "Poisson\351\207\215\345\273\272\347\232\204\345\205\253\345\217\211\346\240\221\346\267\261\345\272\246\357\274\214\345\200\274\350\266\212\345\244\247\347\275\221\346\240\274\350\266\212\347\262\276\347\273\206 (\351\273\230\350\256\24411\357\274\214\345\257\271\346\240\221\346\234\250\347\255\211\345\244\215\346\235\202\347\273\223\346\236\204\345\273\272\350\256\25611\346\210\22612)", nullptr));
#endif // QT_CONFIG(tooltip)
        label_mesh7->setText(QCoreApplication::translate("ConfigDialog", "\346\234\200\345\260\217\345\257\206\345\272\246\350\277\207\346\273\244\351\230\210\345\200\274\345\210\206\344\275\215\346\225\260 \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        label_mesh7->setToolTip(QCoreApplication::translate("ConfigDialog", "Poisson\351\207\215\345\273\272\347\232\204\346\234\200\345\260\217\345\257\206\345\272\246\350\277\207\346\273\244\351\230\210\345\200\274\345\210\206\344\275\215\346\225\260\357\274\214\351\231\215\344\275\216\346\255\244\345\200\274\345\217\257\344\277\235\347\225\231\346\233\264\345\244\232\346\240\221\345\217\266\350\276\271\347\274\230\347\273\206\350\212\202 (\345\216\2370.02 -> 0.005)", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBoxPre->setTitle(QCoreApplication::translate("ConfigDialog", "\351\242\204\345\244\204\347\220\206\344\270\216\344\274\240\346\204\237\345\231\250", nullptr));
        label_pre1->setText(QCoreApplication::translate("ConfigDialog", "LAS \350\207\252\345\212\250\345\210\206\345\211\262\351\230\210\345\200\274 (MB) \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        label_pre1->setToolTip(QCoreApplication::translate("ConfigDialog", "LAS \347\202\271\344\272\221\346\226\207\344\273\266\350\207\252\345\212\250\345\210\206\345\211\262\345\244\247\345\260\217\351\230\210\345\200\274 (\345\215\225\344\275\215: MB)\357\274\232\n"
"\344\270\272\344\272\206\351\230\262\346\255\242\345\244\204\347\220\206\350\266\205\345\244\247\345\260\272\345\257\270\347\202\271\344\272\221\346\226\207\344\273\266\346\227\266\345\257\274\350\207\264\345\206\205\345\255\230\346\272\242\345\207\272 (OOM) \346\210\226\345\244\204\347\220\206\346\236\201\345\205\266\347\274\223\346\205\242\343\200\202\n"
"\345\275\223\350\276\223\345\205\245\347\232\204 LAS \346\226\207\344\273\266\345\244\247\345\260\217\350\266\205\350\277\207\346\255\244\351\230\210\345\200\274\346\227\266\357\274\214\347\263\273\347\273\237\344\274\232\350\207\252\345\212\250\350\260\203\347\224\250 split_las.py \345\260\206\345\205\266\346\213\206\345\210\206\344\270\272\345\244\232\344\270\252\345\260\217\346\226\207\344\273\266\357\274\214\n"
"\347\204\266\345\220\216\351\200\220\345\235\227 "
                        "(chunk-by-chunk) \346\224\276\345\205\245\346\265\201\346\260\264\347\272\277\350\277\233\350\241\214\344\270\211\347\273\264\351\207\215\345\273\272\345\222\214\347\272\271\347\220\206\346\230\240\345\260\204\343\200\202\n"
"\351\273\230\350\256\244\344\270\272 500 (MB)\343\200\202", nullptr));
#endif // QT_CONFIG(tooltip)
        label_pre2->setText(QCoreApplication::translate("ConfigDialog", "\345\205\250\346\231\257\347\233\270\346\234\272\351\225\234\345\244\264\346\225\260 \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        label_pre2->setToolTip(QCoreApplication::translate("ConfigDialog", "\345\205\250\346\231\257\347\233\270\346\234\272\345\214\205\345\220\253\347\232\204\347\211\251\347\220\206\351\225\234\345\244\264\346\225\260\351\207\217\357\274\232\n"
"Ladybug5+ \347\255\211\347\273\217\345\205\270\345\205\250\346\231\257\347\233\270\346\234\272\351\200\232\345\270\270\347\224\261 6 \350\267\257\357\274\2105\344\270\252\344\276\247\351\235\242+1\344\270\252\351\241\266\351\203\250\357\274\211\351\225\234\345\244\264\346\213\274\346\216\245\350\200\214\346\210\220\343\200\202\n"
"\346\237\220\344\272\233\350\275\273\351\207\217\345\214\226\350\256\276\345\244\207\345\217\257\350\203\275\347\224\261 2 \350\267\257\357\274\210\345\211\215\345\220\216\344\270\244\344\270\252\351\261\274\347\234\274\351\225\234\345\244\264\357\274\211\346\213\274\346\216\245\350\200\214\346\210\220\343\200\202\n"
"\350\260\203\346\225\264\346\255\244\345\217\202\346\225\260\345\217\257\350\203\275\344\274\232\345\275\261\345\223\215\345\220\216\347\273\255\347\232\204\347\225\270\345\217\230\347\237\253\346\255"
                        "\243\344\270\216\346\230\240\345\260\204\347\255\226\347\225\245\357\274\210\347\233\256\345\211\215\351\273\230\350\256\244\346\214\211 6 \350\267\257\347\255\211\350\267\235\345\234\206\346\237\261\346\212\225\345\275\261\345\244\204\347\220\206\357\274\211\343\200\202", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBoxTex->setTitle(QCoreApplication::translate("ConfigDialog", "\347\272\271\347\220\206\346\230\240\345\260\204\344\270\216\346\225\260\346\215\256\346\240\241\351\252\214", nullptr));
        label_tex1->setText(QCoreApplication::translate("ConfigDialog", "\345\274\200\345\220\257\347\202\271\344\272\221\347\203\230\347\204\231 \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        label_tex1->setToolTip(QCoreApplication::translate("ConfigDialog", "\346\230\257\345\220\246\345\274\200\345\220\257\347\202\271\344\272\221\347\203\230\347\204\231 (Point Cloud Baking)\357\274\232\n"
"\345\246\202\346\236\234\346\202\250\347\232\204\345\216\237\345\247\213\347\202\271\344\272\221\346\225\260\346\215\256\346\234\252\347\235\200\350\211\262 (\346\227\240 RGB \345\255\227\346\256\265)\357\274\214\345\273\272\350\256\256\350\256\276\347\275\256\344\270\272 false\343\200\202\n"
"\350\256\276\347\275\256\344\270\272 false \346\227\266\357\274\214\347\263\273\347\273\237\345\260\206\347\233\264\346\216\245\351\207\207\347\224\250\347\233\270\351\202\273\350\247\206\350\247\222\347\233\270\346\234\272\347\232\204\347\205\247\347\211\207\350\264\264\345\233\276\345\257\271\350\275\246\350\272\253\347\233\262\345\214\272\350\277\233\350\241\214\345\205\234\345\272\225\344\277\256\350\241\245\343\200\202\n"
"\350\256\276\347\275\256\344\270\272 true \346\227\266\357\274\214\344\274\230\345\205\210\345\260\235\350\257\225\344\273\216\347\202\271\344\272\221\350\207\252\350"
                        "\272\253\346\217\220\345\217\226\351\242\234\350\211\262\350\277\233\350\241\214\347\203\230\347\204\231\357\274\214\345\244\261\350\264\245\346\227\266\345\206\215\344\275\277\347\224\250\347\205\247\347\211\207\350\264\264\345\233\276\345\205\234\345\272\225\343\200\202", nullptr));
#endif // QT_CONFIG(tooltip)
        chk_enable_point_cloud_baking->setText(QCoreApplication::translate("ConfigDialog", "\345\274\200\345\220\257", nullptr));
        label_tex2->setText(QCoreApplication::translate("ConfigDialog", "Mask \345\256\275\345\272\246\347\274\251\346\224\276 \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        label_tex2->setToolTip(QCoreApplication::translate("ConfigDialog", "\350\275\246\351\241\266/\350\275\246\345\272\225\347\202\271\344\272\221\347\203\230\347\204\231\345\214\272\345\237\237 (Mask) \347\232\204\345\212\250\346\200\201\346\211\251\345\261\225\347\274\251\346\224\276\347\263\273\346\225\260\357\274\232\n"
"\345\260\206\346\240\270\345\277\203\346\216\251\350\206\234\345\234\250\347\211\251\347\220\206\345\260\272\345\257\270\344\270\212\350\277\233\350\241\214\346\213\211\344\274\270\357\274\214\345\275\242\346\210\220\350\277\236\351\200\232\347\232\204\346\225\264\344\275\223\347\203\230\347\204\231\351\200\232\351\201\223\343\200\202\n"
"\345\256\275\345\272\246\347\274\251\346\224\276 (scale_width): 1.4 \345\267\246\345\217\263\346\213\223\345\256\275\357\274\214\347\241\256\344\277\235\350\246\206\347\233\226\350\275\246\350\272\253\344\270\244\344\276\247\347\224\261\344\272\216\351\201\256\346\214\241\346\210\226\351\230\264\345\275\261\344\272\247\347\224\237\347\232\204\351\273\221\350\211\262\347\233\262\345\214\272\357\274\214\345\271\266\345\256\214\346"
                        "\225\264\345\214\205\350\243\271\347\233\270\351\202\273\350\275\246\351\201\223\347\272\277\343\200\202", nullptr));
#endif // QT_CONFIG(tooltip)
        label_tex3->setText(QCoreApplication::translate("ConfigDialog", "Mask \351\225\277\345\272\246\347\274\251\346\224\276 \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        label_tex3->setToolTip(QCoreApplication::translate("ConfigDialog", "\350\275\246\351\241\266/\350\275\246\345\272\225\347\202\271\344\272\221\347\203\230\347\204\231\345\214\272\345\237\237 (Mask) \347\232\204\345\212\250\346\200\201\346\211\251\345\261\225\347\274\251\346\224\276\347\263\273\346\225\260\357\274\232\n"
"\345\260\206\346\240\270\345\277\203\346\216\251\350\206\234\345\234\250\347\211\251\347\220\206\345\260\272\345\257\270\344\270\212\350\277\233\350\241\214\346\213\211\344\274\270\357\274\214\345\275\242\346\210\220\350\277\236\351\200\232\347\232\204\346\225\264\344\275\223\347\203\230\347\204\231\351\200\232\351\201\223\343\200\202\n"
"\351\225\277\345\272\246\347\274\251\346\224\276 (scale_length): 3.0 \345\211\215\345\220\216\346\213\211\351\225\277\357\274\214\344\275\277\345\211\215\345\220\216\345\270\247\347\232\204\347\203\230\347\204\231\345\214\272\345\237\237\350\203\275\345\244\237\351\246\226\345\260\276\347\233\270\350\277\236\345\275\242\346\210\220\350\277\236\347\273\255\346\235\241\345\270\246\343\200\202", nullptr));
#endif // QT_CONFIG(tooltip)
        label_tex4->setText(QCoreApplication::translate("ConfigDialog", "\346\234\200\345\244\247\345\205\201\350\256\270\347\233\270\346\234\272\345\237\272\347\272\277 (\347\261\263) \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        label_tex4->setToolTip(QCoreApplication::translate("ConfigDialog", "\346\234\200\345\244\247\345\205\201\350\256\270\347\233\270\346\234\272\345\237\272\347\272\277 (\347\261\263)\357\274\232\n"
"\347\233\270\351\202\273\344\270\244\346\254\241\346\213\215\347\205\247\347\232\204\350\247\246\345\217\221\351\227\264\350\267\235\343\200\202\350\266\205\350\277\207\346\255\244\345\200\274\344\274\232\345\234\250\345\211\224\351\231\244\350\275\246\351\241\266\351\201\256\346\214\241\345\220\216\357\274\214\345\257\274\350\207\264\350\241\245\345\233\276\346\227\266\345\207\272\347\216\260\344\270\245\351\207\215\347\232\204\346\216\240\345\260\204\350\247\222\346\213\211\344\274\270\343\200\202", nullptr));
#endif // QT_CONFIG(tooltip)
        label_tex5->setText(QCoreApplication::translate("ConfigDialog", "\346\234\200\345\260\217\345\205\201\350\256\270\346\216\240\345\260\204\350\247\222 (\345\272\246) \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        label_tex5->setToolTip(QCoreApplication::translate("ConfigDialog", "\346\234\200\345\260\217\345\205\201\350\256\270\350\247\202\346\265\213\346\216\240\345\260\204\350\247\222 (\345\272\246)\357\274\232\n"
"\344\274\260\347\256\227\347\232\204\350\241\245\347\233\262\347\233\270\346\234\272\344\277\257\350\247\206\350\247\222\343\200\202\344\275\216\344\272\216\346\255\244\350\247\206\350\247\222\344\274\232\345\257\274\350\207\264\350\275\246\345\272\225\345\214\272\345\237\237\347\224\261\344\272\216\345\207\240\344\275\225\345\276\256\345\260\217\350\257\257\345\267\256\344\272\247\347\224\237\346\236\201\347\253\257\351\224\231\344\275\215\345\215\260\347\227\225\343\200\202", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBoxSign->setTitle(QCoreApplication::translate("ConfigDialog", "\350\267\257\347\211\214\346\243\200\346\265\213\344\270\216\350\241\245\351\275\220", nullptr));
        label_sign1->setText(QCoreApplication::translate("ConfigDialog", "\345\220\257\347\224\250\350\267\257\347\211\214\351\207\215\345\273\272 \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        label_sign1->setToolTip(QCoreApplication::translate("ConfigDialog", "\350\267\257\347\211\214\346\243\200\346\265\213\344\270\216\345\210\206\345\211\262\346\200\273\345\274\200\345\205\263\357\274\232\n"
"\350\256\276\347\275\256\344\270\272 false \346\227\266\357\274\214\345\260\206\350\267\263\350\277\207\346\211\200\346\234\211\350\267\257\347\211\214\347\232\204\346\243\200\346\265\213\343\200\201\345\210\206\345\211\262\345\222\214 3D \351\207\215\345\273\272\350\241\245\351\275\220\346\265\201\347\250\213\357\274\214\346\236\201\345\244\247\345\212\240\345\277\253\346\225\264\344\275\223\345\244\204\347\220\206\351\200\237\345\272\246\357\274\214\346\226\271\344\276\277\345\277\253\351\200\237\351\242\204\350\247\210\350\267\257\351\235\242\343\200\202", nullptr));
#endif // QT_CONFIG(tooltip)
        chk_sign_enabled->setText(QCoreApplication::translate("ConfigDialog", "\345\274\200\345\220\257", nullptr));
        label_sign2->setText(QCoreApplication::translate("ConfigDialog", "\346\234\200\345\244\247\346\217\220\345\217\226\350\267\235\347\246\273 (\347\261\263) \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        label_sign2->setToolTip(QCoreApplication::translate("ConfigDialog", "\346\234\200\345\244\247\346\217\220\345\217\226\350\267\235\347\246\273 (\347\261\263)\357\274\232\347\224\261\344\272\216\345\205\250\346\231\257\345\233\276\345\203\217\347\264\240\347\225\270\345\217\230\345\222\214\351\200\217\350\247\206\345\205\263\347\263\273\357\274\214\350\267\235\347\246\273\345\244\252\350\277\234\347\232\204\350\267\257\347\211\214\346\243\200\346\265\213\346\241\206\345\222\214\345\210\206\345\211\262\345\256\271\346\230\223\344\272\247\347\224\237\346\236\201\345\244\247\350\257\257\345\267\256\343\200\202\n"
"\350\266\205\350\277\207\346\255\244\350\267\235\347\246\273\347\232\204\350\267\257\347\211\214\345\234\250\345\275\223\345\211\215\345\270\247\345\260\206\350\242\253\345\277\275\347\225\245\357\274\214\347\255\211\345\276\205\350\275\246\350\276\206\351\235\240\350\277\221\345\220\216\345\206\215\346\217\220\345\217\226\343\200\202", nullptr));
#endif // QT_CONFIG(tooltip)
        label_sign3->setText(QCoreApplication::translate("ConfigDialog", "\346\234\200\345\260\217 Z \350\275\264\351\253\230\345\272\246 (\347\261\263) \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        label_sign3->setToolTip(QCoreApplication::translate("ConfigDialog", "\346\234\200\345\260\217\351\253\230\345\272\246\351\230\210\345\200\274 (\347\261\263)\357\274\232\347\234\237\345\256\236\350\267\257\347\211\214\351\200\232\345\270\270\346\202\254\346\214\202\345\234\250\345\215\212\347\251\272\346\210\226\346\234\211\347\253\213\346\237\261\346\224\257\346\222\221\343\200\202\n"
"Z \350\275\264\351\253\230\345\272\246\357\274\210\347\233\270\345\257\271\344\272\216\345\275\223\345\211\215\350\267\257\351\235\242\357\274\211\344\275\216\344\272\216\346\255\244\345\200\274\347\232\204\346\243\200\346\265\213\347\273\223\346\236\234\345\260\206\350\242\253\345\210\244\345\256\232\344\270\272\345\273\272\347\255\221\345\272\225\345\261\202\351\227\250\347\252\227\346\210\226\345\234\260\351\235\242\345\271\262\346\211\260\347\211\251\345\271\266\345\211\224\351\231\244\343\200\202", nullptr));
#endif // QT_CONFIG(tooltip)
        label_sign4->setText(QCoreApplication::translate("ConfigDialog", "\350\201\232\347\261\273\345\216\273\351\207\215\350\267\235\347\246\273\351\230\210\345\200\274 (\347\261\263) \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        label_sign4->setToolTip(QCoreApplication::translate("ConfigDialog", "\350\201\232\347\261\273\345\216\273\351\207\215\350\267\235\347\246\273\351\230\210\345\200\274 (\347\261\263)\357\274\232\345\220\214\344\270\200\350\267\257\347\211\214\345\217\257\350\203\275\345\234\250\350\277\236\347\273\255\345\244\232\345\270\247\344\270\255\350\242\253\346\243\200\346\265\213\345\271\266\346\236\204\345\273\272\344\272\206\345\244\232\344\270\252\346\236\201\345\205\266\346\216\245\350\277\221\347\232\204 3D \347\275\221\346\240\274\343\200\202\n"
"\344\270\255\345\277\203\347\202\271\350\267\235\347\246\273\345\260\217\344\272\216\346\255\244\345\200\274\347\232\204\347\275\221\346\240\274\345\260\206\350\242\253\345\210\244\345\256\232\344\270\272\345\220\214\344\270\200\344\270\252\350\267\257\347\211\214\357\274\214\345\271\266\345\217\252\344\277\235\347\225\231\351\235\242\347\247\257\346\234\200\345\244\247\343\200\201\346\234\200\345\256\214\346\225\264\347\232\204\351\202\243\344\270\252\357\274\214\344\273\245\346\266\210\351\231\244\347\272\271\347\220\206\347\242\216\347\211"
                        "\207\345\214\226\343\200\202", nullptr));
#endif // QT_CONFIG(tooltip)
        label_sign5->setText(QCoreApplication::translate("ConfigDialog", "\345\214\205\345\233\264\347\233\222\350\243\201\345\211\252\347\274\251\346\224\276\347\263\273\346\225\260 \360\237\233\210:", nullptr));
#if QT_CONFIG(tooltip)
        label_sign5->setToolTip(QCoreApplication::translate("ConfigDialog", "OBB / AABB \345\214\205\345\233\264\347\233\222\350\243\201\345\211\252\347\274\251\346\224\276\347\263\273\346\225\260\357\274\232\n"
"\345\260\206\350\241\245\351\275\220\347\232\204\345\256\214\347\276\216\350\267\257\347\211\214\347\275\221\346\240\274\345\220\210\345\271\266\345\233\236\344\270\273\346\250\241\345\236\213\345\211\215\357\274\214\351\234\200\350\246\201\345\210\240\346\216\211\345\216\237\346\235\245\346\256\213\347\274\272\347\232\204\347\202\271\344\272\221\343\200\202\350\277\231\344\270\252\347\263\273\346\225\260\346\216\247\345\210\266\350\243\201\345\211\252\345\214\205\345\233\264\347\233\222\347\232\204\345\244\247\345\260\217\343\200\202\n"
"\350\256\276\344\270\272 1.1 \344\273\205\345\210\207\351\231\244\350\267\257\347\211\214\351\231\204\350\277\221\347\232\204\346\256\213\347\274\272\351\243\236\350\276\271\357\274\214\345\246\202\346\236\234\350\256\276\345\276\227\345\244\252\345\244\247(\345\246\202 2.0)\345\256\271\346\230\223\350\257\257\345\210\240\345\234\260\351\235\242"
                        "\346\210\226\346\240\221\346\234\250\343\200\202", nullptr));
#endif // QT_CONFIG(tooltip)
        btnRestoreDefault->setText(QCoreApplication::translate("ConfigDialog", "\346\201\242\345\244\215\351\273\230\350\256\244\351\205\215\347\275\256", nullptr));
        btnSave->setText(QCoreApplication::translate("ConfigDialog", "\344\277\235\345\255\230", nullptr));
        btnCancel->setText(QCoreApplication::translate("ConfigDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfigDialog: public Ui_ConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGDIALOG_H

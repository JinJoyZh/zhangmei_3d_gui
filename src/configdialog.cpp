#include "configdialog.h"
#include "ui_configdialog.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QRegularExpression>
#include <QDebug>

const QString DEFAULT_CONFIG = R"(# 调试日志开关：
# 是否输出额外的中间调试信息，如将检测与分割的中间结果图像（包含检测框和 SAM 掩膜）
# 保存到每个分段的 images 文件夹下以供调试。
debug_log_enabled: true

mesh_filtering:
  # 距离地面多高以上的网格将进行点云到网格的距离验证，剔除“天空飞面”
  sky_mesh_height_threshold: 1.2
  
  # 轨迹点（相机/车顶）距离地面的大概高度 (米)
  camera_height: 2.0
  
  # 核心安全点距离容差：距离点云小于此值的顶点被认为是绝对安全的“核心点” (原 0.05m)
  sky_mesh_core_tolerance: 0.05
  
  # 放宽距离容差：距离点云在此值范围内，且与“核心点”相连的顶点，将被作为合法边缘保留
  sky_mesh_relaxed_tolerance: 0.20
  
  # 连通边长阈值：只有当顶点与核心点之间的边长小于此值时，才认为它们是“紧密连接”的，防止飞面被意外感染保留
  sky_mesh_max_edge_length: 0.30
  
  # Poisson重建的八叉树深度，值越大网格越精细 (默认10，对树木等复杂结构建议11或12)
  poisson_depth: 11

  # Poisson重建的最小密度过滤阈值分位数，降低此值可保留更多树叶边缘细节 (原0.02 -> 0.005)
  poisson_density_quantile: 0.005

# === 数据预处理参数 (Data Preprocessing Parameters) ===
preprocessing:
  # LAS 点云文件自动分割大小阈值 (单位: MB)：
  # 为了防止处理超大尺寸点云文件时导致内存溢出 (OOM) 或处理极其缓慢。
  # 当输入的 LAS 文件大小超过此阈值时，系统会自动调用 split_las.py 将其拆分为多个小文件，
  # 然后逐块 (chunk-by-chunk) 放入流水线进行三维重建和纹理映射。
  # 默认为 500 (MB)。
  auto_split_max_size_mb: 500

# === 图像与传感器参数 (Image & Sensor Parameters) ===
sensor:
  # 全景相机包含的物理镜头数量：
  # Ladybug5+ 等经典全景相机通常由 6 路（5个侧面+1个顶部）镜头拼接而成。
  # 某些轻量化设备可能由 2 路（前后两个鱼眼镜头）拼接而成。
  # 调整此参数可能会影响后续的畸变矫正与映射策略（目前默认按 6 路等距圆柱投影处理）。
  camera_count: 6

# === 纹理映射参数 (Texture Mapping Parameters) ===
texture_mapping:
  # 是否开启点云烘焙 (Point Cloud Baking)：
  # 如果您的原始点云数据未着色 (无 RGB 字段)，建议设置为 false。
  # 设置为 false 时，系统将直接采用相邻视角相机的照片贴图对车身盲区进行兜底修补。
  # 设置为 true 时，优先尝试从点云自身提取颜色进行烘焙，失败时再使用照片贴图兜底。
  enable_point_cloud_baking: false

  # 车顶/车底点云烘焙区域 (Mask) 的动态扩展缩放系数：
  # 将核心掩膜在物理尺寸上进行拉伸，形成连通的整体烘焙通道。
  # 宽度缩放 (scale_width): 1.4 左右拓宽，确保覆盖车身两侧由于遮挡或阴影产生的黑色盲区，并完整包裹相邻车道线。
  # 长度缩放 (scale_length): 3.0 前后拉长，使前后帧的烘焙区域能够首尾相连形成连续条带。
  mask_scale_width: 1.05
  mask_scale_length: 1.05

# === 数据质量校验参数 (Data Quality Validation Parameters) ===
data_quality:
  # 最大允许相机基线 (米)：
  # 相邻两次拍照的触发间距。超过此值会在剔除车顶遮挡后，导致补图时出现严重的掠射角拉伸。
  max_baseline_warning: 4.0
  
  # 最小允许观测掠射角 (度)：
  # 估算的补盲相机俯视角。低于此视角会导致车底区域由于几何微小误差产生极端错位印痕。
  min_grazing_angle_warning: 35.0

# === 路牌检测与补齐超参数 (Sign Reconstruction Parameters) ===
sign_reconstruction:
  # 路牌检测与分割总开关：
  # 设置为 false 时，将跳过所有路牌的检测、分割和 3D 重建补齐流程，极大加快整体处理速度，方便快速预览路面。
  enabled: true

  # 最大提取距离 (米)：由于全景图像素畸变和透视关系，距离太远的路牌检测框和分割容易产生极大误差。
  # 超过此距离的路牌在当前帧将被忽略，等待车辆靠近后再提取。
  max_distance_to_cam: 20.0
  
  # 最小高度阈值 (米)：真实路牌通常悬挂在半空或有立柱支撑。
  # Z 轴高度（相对于当前路面）低于此值的检测结果将被判定为建筑底层门窗或地面干扰物并剔除。
  min_z_height: 1.5
  
  # 聚类去重距离阈值 (米)：同一路牌可能在连续多帧中被检测并构建了多个极其接近的 3D 网格。
  # 中心点距离小于此值的网格将被判定为同一个路牌，并只保留面积最大、最完整的那个，以消除纹理碎片化。
  clustering_distance: 1.5
  
  # OBB / AABB 包围盒裁剪缩放系数：
  # 将补齐的完美路牌网格合并回主模型前，需要删掉原来残缺的点云。这个系数控制裁剪包围盒的大小。
  # 设为 1.1 仅切除路牌附近的残缺飞边，如果设得太大(如 2.0)容易误删地面或树木。
  bbox_crop_scale: 1.1
)";

ConfigDialog::ConfigDialog(const QString &configFilePath, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ConfigDialog)
    , m_configFilePath(configFilePath)
{
    ui->setupUi(this);
    loadConfig();
}

ConfigDialog::~ConfigDialog()
{
    delete ui;
}

void ConfigDialog::loadConfig()
{
    QFile file(m_configFilePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        in.setCodec("UTF-8");
        m_currentYamlContent = in.readAll();
        file.close();
    } else {
        // If file doesn't exist or can't be opened, load default
        m_currentYamlContent = DEFAULT_CONFIG;
    }
    parseYamlToUI();
}

void ConfigDialog::parseYamlToUI()
{
    // A simple regex parser to extract values line by line
    QStringList lines = m_currentYamlContent.split('\n');
    QString currentSection = "";
    
    for (const QString &line : lines) {
        QString tLine = line.trimmed();
        if (tLine.isEmpty() || tLine.startsWith("#")) continue;
        
        if (tLine.endsWith(":") && !line.startsWith(" ")) {
            currentSection = tLine.left(tLine.length() - 1);
            continue;
        }
        
        int colonIdx = tLine.indexOf(":");
        if (colonIdx != -1) {
            QString key = tLine.left(colonIdx).trimmed();
            QString valStr = tLine.mid(colonIdx + 1).split("#")[0].trimmed(); // Ignore inline comments
            
            if (currentSection == "") {
                if (key == "debug_log_enabled") ui->chk_debug_log_enabled->setChecked(valStr.toLower() == "true");
            } 
            else if (currentSection == "mesh_filtering") {
                if (key == "sky_mesh_height_threshold") ui->spin_sky_mesh_height_threshold->setValue(valStr.toDouble());
                else if (key == "camera_height") ui->spin_camera_height->setValue(valStr.toDouble());
                else if (key == "sky_mesh_core_tolerance") ui->spin_sky_mesh_core_tolerance->setValue(valStr.toDouble());
                else if (key == "sky_mesh_relaxed_tolerance") ui->spin_sky_mesh_relaxed_tolerance->setValue(valStr.toDouble());
                else if (key == "sky_mesh_max_edge_length") ui->spin_sky_mesh_max_edge_length->setValue(valStr.toDouble());
                else if (key == "poisson_depth") ui->spin_poisson_depth->setValue(valStr.toInt());
                else if (key == "poisson_density_quantile") ui->spin_poisson_density_quantile->setValue(valStr.toDouble());
            }
            else if (currentSection == "preprocessing") {
                if (key == "auto_split_max_size_mb") ui->spin_auto_split_max_size_mb->setValue(valStr.toInt());
            }
            else if (currentSection == "sensor") {
                if (key == "camera_count") ui->spin_camera_count->setValue(valStr.toInt());
            }
            else if (currentSection == "texture_mapping") {
                if (key == "enable_point_cloud_baking") ui->chk_enable_point_cloud_baking->setChecked(valStr.toLower() == "true");
                else if (key == "mask_scale_width") ui->spin_mask_scale_width->setValue(valStr.toDouble());
                else if (key == "mask_scale_length") ui->spin_mask_scale_length->setValue(valStr.toDouble());
            }
            else if (currentSection == "data_quality") {
                if (key == "max_baseline_warning") ui->spin_max_baseline_warning->setValue(valStr.toDouble());
                else if (key == "min_grazing_angle_warning") ui->spin_min_grazing_angle_warning->setValue(valStr.toDouble());
            }
            else if (currentSection == "sign_reconstruction") {
                if (key == "enabled") ui->chk_sign_enabled->setChecked(valStr.toLower() == "true");
                else if (key == "max_distance_to_cam") ui->spin_sign_max_distance_to_cam->setValue(valStr.toDouble());
                else if (key == "min_z_height") ui->spin_sign_min_z_height->setValue(valStr.toDouble());
                else if (key == "clustering_distance") ui->spin_sign_clustering_distance->setValue(valStr.toDouble());
                else if (key == "bbox_crop_scale") ui->spin_sign_bbox_crop_scale->setValue(valStr.toDouble());
            }
        }
    }
}

QString ConfigDialog::updateYamlValue(QString yaml, const QString& section, const QString& key, const QString& val)
{
    QStringList lines = yaml.split('\n');
    QString currentSection = "";
    bool inTargetSection = section.isEmpty();
    
    for (int i = 0; i < lines.size(); ++i) {
        QString line = lines[i];
        QString tLine = line.trimmed();
        
        if (!tLine.startsWith("#") && tLine.contains(":") && !line.startsWith(" ")) {
            currentSection = tLine.left(tLine.indexOf(":")).trimmed();
            inTargetSection = (currentSection == section);
        }
        
        if (inTargetSection && tLine.startsWith(key + ":")) {
            int colonIdx = line.indexOf(":");
            int hashIdx = line.indexOf("#", colonIdx);
            QString comment = "";
            if (hashIdx != -1) {
                comment = " " + line.mid(hashIdx);
            }
            QString indent = line.left(line.indexOf(key));
            lines[i] = indent + key + ": " + val + comment;
            return lines.join('\n');
        }
    }
    return yaml;
}

void ConfigDialog::saveUIToYaml()
{
    QString yaml = m_currentYamlContent;
    
    auto boolToStr = [](bool b) { return b ? "true" : "false"; };
    
    yaml = updateYamlValue(yaml, "", "debug_log_enabled", boolToStr(ui->chk_debug_log_enabled->isChecked()));
    
    yaml = updateYamlValue(yaml, "mesh_filtering", "sky_mesh_height_threshold", QString::number(ui->spin_sky_mesh_height_threshold->value()));
    yaml = updateYamlValue(yaml, "mesh_filtering", "camera_height", QString::number(ui->spin_camera_height->value()));
    yaml = updateYamlValue(yaml, "mesh_filtering", "sky_mesh_core_tolerance", QString::number(ui->spin_sky_mesh_core_tolerance->value()));
    yaml = updateYamlValue(yaml, "mesh_filtering", "sky_mesh_relaxed_tolerance", QString::number(ui->spin_sky_mesh_relaxed_tolerance->value()));
    yaml = updateYamlValue(yaml, "mesh_filtering", "sky_mesh_max_edge_length", QString::number(ui->spin_sky_mesh_max_edge_length->value()));
    yaml = updateYamlValue(yaml, "mesh_filtering", "poisson_depth", QString::number(ui->spin_poisson_depth->value()));
    yaml = updateYamlValue(yaml, "mesh_filtering", "poisson_density_quantile", QString::number(ui->spin_poisson_density_quantile->value(), 'f', 4));
    
    yaml = updateYamlValue(yaml, "preprocessing", "auto_split_max_size_mb", QString::number(ui->spin_auto_split_max_size_mb->value()));
    
    yaml = updateYamlValue(yaml, "sensor", "camera_count", QString::number(ui->spin_camera_count->value()));
    
    yaml = updateYamlValue(yaml, "texture_mapping", "enable_point_cloud_baking", boolToStr(ui->chk_enable_point_cloud_baking->isChecked()));
    yaml = updateYamlValue(yaml, "texture_mapping", "mask_scale_width", QString::number(ui->spin_mask_scale_width->value()));
    yaml = updateYamlValue(yaml, "texture_mapping", "mask_scale_length", QString::number(ui->spin_mask_scale_length->value()));
    
    yaml = updateYamlValue(yaml, "data_quality", "max_baseline_warning", QString::number(ui->spin_max_baseline_warning->value()));
    yaml = updateYamlValue(yaml, "data_quality", "min_grazing_angle_warning", QString::number(ui->spin_min_grazing_angle_warning->value()));
    
    yaml = updateYamlValue(yaml, "sign_reconstruction", "enabled", boolToStr(ui->chk_sign_enabled->isChecked()));
    yaml = updateYamlValue(yaml, "sign_reconstruction", "max_distance_to_cam", QString::number(ui->spin_sign_max_distance_to_cam->value()));
    yaml = updateYamlValue(yaml, "sign_reconstruction", "min_z_height", QString::number(ui->spin_sign_min_z_height->value()));
    yaml = updateYamlValue(yaml, "sign_reconstruction", "clustering_distance", QString::number(ui->spin_sign_clustering_distance->value()));
    yaml = updateYamlValue(yaml, "sign_reconstruction", "bbox_crop_scale", QString::number(ui->spin_sign_bbox_crop_scale->value()));
    
    m_currentYamlContent = yaml;
}

void ConfigDialog::on_btnRestoreDefault_clicked()
{
    int ret = QMessageBox::question(this, "确认", "确定要恢复默认配置吗？这将覆盖当前的修改。",
                                    QMessageBox::Yes | QMessageBox::No);
    if (ret == QMessageBox::Yes) {
        m_currentYamlContent = DEFAULT_CONFIG;
        parseYamlToUI();
    }
}

void ConfigDialog::on_btnSave_clicked()
{
    saveUIToYaml();
    
    QFile file(m_configFilePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out.setCodec("UTF-8");
        out << m_currentYamlContent;
        file.close();
        QMessageBox::information(this, "成功", "配置已保存。");
        accept();
    } else {
        QMessageBox::warning(this, "错误", "无法保存配置文件，请检查权限。");
    }
}

void ConfigDialog::on_btnCancel_clicked()
{
    reject();
}

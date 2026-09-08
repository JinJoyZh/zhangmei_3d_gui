cmake_minimum_required(VERSION 3.5)
project(zhongmei_3d_gui LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt5 or Qt6
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Gui Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui Widgets REQUIRED)

add_executable(zhongmei_3d_gui
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.h
    src/dockermanager.cpp
    src/dockermanager.h
    ui/mainwindow.ui
)

target_link_libraries(zhongmei_3d_gui 
    Qt${QT_VERSION_MAJOR}::Core 
    Qt${QT_VERSION_MAJOR}::Gui 
    Qt${QT_VERSION_MAJOR}::Widgets
)

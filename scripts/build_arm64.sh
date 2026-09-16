#!/usr/bin/env bash
set -Eeuo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
GUI_DIR="$(cd "${SCRIPT_DIR}/.." && pwd)"
BUILD_DIR="${GUI_DIR}/build-arm64"

if [[ "$(uname -m)" != "aarch64" ]]; then
    echo "错误：该脚本必须在 ARM64 Linux 主机上运行，当前架构为 $(uname -m)。" >&2
    exit 1
fi

if command -v qmake >/dev/null 2>&1; then
    QMAKE_BIN="$(command -v qmake)"
elif command -v qmake-qt5 >/dev/null 2>&1; then
    QMAKE_BIN="$(command -v qmake-qt5)"
else
    echo "错误：未找到 Qt5 qmake，请先安装 Qt5 开发包和 C++ 编译工具。" >&2
    exit 1
fi

mkdir -p "${BUILD_DIR}"
cd "${BUILD_DIR}"
"${QMAKE_BIN}" "${GUI_DIR}/gui.pro" CONFIG+=release
make -j"$(nproc)"

test -x "${BUILD_DIR}/gui"
file "${BUILD_DIR}/gui"
if ! file "${BUILD_DIR}/gui" | grep -Eq 'ARM aarch64|ARM64'; then
    echo "错误：GUI 构建结果不是 ARM64 可执行文件。" >&2
    exit 1
fi

cp "${BUILD_DIR}/gui" "${BUILD_DIR}/zhongmei_3d_gui"
echo "ARM64 GUI 已生成：${BUILD_DIR}/zhongmei_3d_gui"

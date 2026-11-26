#!/usr/bin/env bash
set -euo pipefail

PROJECT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
COMMON_SCRIPT="$PROJECT_DIR/build_common.sh"

MODULES_DIR="include"
MODULES=(
    "core/core.cppm"
    "tools/helptool.cppm"
)

MAIN_SRC="example.cpp"
TARGET_BASE_NAME="example-test"
BUILD_DIR="build"

# shellcheck source=/dev/null
source "$COMMON_SCRIPT"
run_module_build_cli "${1:-run}"
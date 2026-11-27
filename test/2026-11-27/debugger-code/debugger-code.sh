#!/usr/bin/env bash
set -euo pipefail

PROJECT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
COMMON_SCRIPT="$PROJECT_DIR/../../../scripts/build/build_common.sh"

MODULES_DIR="../../../include"
MODULES=(
    "core/system/hardware/os.cppm"
    "core/time/time.cppm"
)

MAIN_SRC="debugger-code.cpp"
TARGET_BASE_NAME="debugger-code"
BUILD_DIR="build"

# shellcheck source=/dev/null
source "$COMMON_SCRIPT"
run_module_build_cli "${1:-run}"
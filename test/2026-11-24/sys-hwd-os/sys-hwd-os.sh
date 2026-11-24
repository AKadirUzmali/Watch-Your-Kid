#!/usr/bin/env bash
set -euo pipefail

# Scriptin bulunduğu dizine geç (farklı klasörden çağırıldığında sorun yaşamamak için)
cd "$(dirname "${BASH_SOURCE[0]}")"

CXX="${CXX:-g++}"
MODULES_DIR="../../../include"
CXXFLAGS=(-std=c++20 -fmodules -Wall -Wextra -I"$MODULES_DIR")
MODULES=(
    "core/system/hardware/os.cppm"
)

MAIN_SRC="sys-hwd-os.cpp"
BUILD_DIR="build"
TARGET_NAME="sys-hwd-os.linux"
# ------------------------------------------------------------------------

TARGET="$BUILD_DIR/$TARGET_NAME"

clean_build() {
    rm -rf "$BUILD_DIR" gcm.cache
}

build_target() {
    mkdir -p "$BUILD_DIR"

    local objs=()
    local mod_path
    local base_name
    local obj_path

    for mod in "${MODULES[@]}"; do
        mod_path="$MODULES_DIR/$mod"
        base_name="$(basename "${mod%.*}")"
        obj_path="$BUILD_DIR/${base_name}.o"

        "$CXX" "${CXXFLAGS[@]}" -x c++ -c "$mod_path" -o "$obj_path"
        objs+=("$obj_path")
    done

    "$CXX" "${CXXFLAGS[@]}" "$MAIN_SRC" "${objs[@]}" -o "$TARGET"
}

case "${1:-run}" in
    build)
        build_target
        ;;
    run)
        build_target
        printf "[SHELL] Running tests...\n\n"
        "$TARGET"
        ;;
    clean)
        clean_build
        printf "[SHELL] Cleaned build artifacts.\n"
        ;;
    rebuild)
        clean_build
        build_target
        printf "[SHELL] Rebuilt and running tests...\n\n"
        "$TARGET"
        ;;
    *)
        printf "[SHELL] Usage: $0 {build|run|clean|rebuild}\n"
        exit 1
        ;;
esac
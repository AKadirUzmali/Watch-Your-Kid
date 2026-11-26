#!/usr/bin/env bash
set -euo pipefail

detect_os() {
    local uname_s
    uname_s="$(uname -s)"

    case "$uname_s" in
        Linux*)
            echo "linux"
            ;;
        FreeBSD*)
            echo "freebsd"
            ;;
        MINGW*|MSYS*|CYGWIN*)
            echo "windows"
            ;;
        *)
            echo "unknown"
            ;;
    esac
}

os_to_folder() {
    local os_type="$1"

    case "$os_type" in
        windows)
            echo "windows"
            ;;
        linux)
            echo "linux"
            ;;
        freebsd)
            echo "bsd"
            ;;
        *)
            echo "unknown"
            ;;
    esac
}

run_module_build_cli() {
    : "${PROJECT_DIR:?PROJECT_DIR is required}"
    : "${MODULES_DIR:?MODULES_DIR is required}"
    : "${MAIN_SRC:?MAIN_SRC is required}"
    : "${TARGET_BASE_NAME:?TARGET_BASE_NAME is required}"

    cd "$PROJECT_DIR"

    local os_type
    os_type="$(detect_os)"

    local os_folder
    os_folder="$(os_to_folder "$os_type")"

    local cxx="${CXX:-g++}"
    local build_root="${BUILD_DIR:-build}"
    local os_build_dir="$build_root/$os_folder"
    local exe_ext=""

    if [[ "$os_type" == "windows" ]]; then
        exe_ext=".exe"
    fi

    local target_rel="${TARGET_BASE_NAME}${exe_ext}"
    local target_abs="$os_build_dir/$target_rel"

    # os_build_dir içinde derleme yapılacağı için göreceli yolları ona göre çözümlüyoruz
    local abs_modules_dir
    abs_modules_dir="$(cd "$MODULES_DIR" && pwd)"
    local abs_main_src="$PROJECT_DIR/$MAIN_SRC"

    local cxxflags=(
        -std=c++20
        -fmodules
        -Wall
        -Wextra
        -I"$abs_modules_dir"
    )

    # İsteğe bağlı ekstra bayraklar dışarıdan EXTRA_CXXFLAGS ile verilebilir
    if [[ -n "${EXTRA_CXXFLAGS:-}" ]]; then
        # shellcheck disable=SC2206
        cxxflags+=($EXTRA_CXXFLAGS)
    fi

    clean_os_build() {
        rm -rf "$os_build_dir"
    }

    build_target() {
        clean_os_build
        mkdir -p "$os_build_dir"

        local objs=()
        local mod
        local mod_path
        local base_name
        local obj_name

        # GCC -fmodules önbelleğini (gcm.cache) bu OS klasöründe izole tutmak için içine giriyoruz
        (
            cd "$os_build_dir"

            # Not: MODULES dizisi import sırasına göre (bağımlılık önce) listelenmelidir
            for mod in "${MODULES[@]}"; do
                mod_path="$abs_modules_dir/$mod"
                base_name="$(basename "${mod%.*}")"
                obj_name="${base_name}.o"

                if [[ ! -f "$mod_path" ]]; then
                    printf "[ERROR] Module file not found: %s\n" "$mod_path" >&2
                    exit 1
                fi

                "$cxx" "${cxxflags[@]}" -x c++ -c "$mod_path" -o "$obj_name"
                objs+=("$obj_name")
            done

            "$cxx" "${cxxflags[@]}" "$abs_main_src" "${objs[@]}" -o "$target_rel"
        )
    }

    local cmd="${1:-run}"
    case "$cmd" in
        build)
            build_target
            printf "[SHELL] Built (%s -> %s): %s\n" "$os_type" "$os_folder" "$target_abs"
            ;;
        run)
            build_target
            printf "[SHELL] Running (%s -> %s): %s\n\n" "$os_type" "$os_folder" "$target_abs"
            "$target_abs"
            ;;
        clean)
            clean_os_build
            printf "[SHELL] Cleaned build directory for '%s' (%s).\n" "$os_folder" "$os_build_dir"
            ;;
        rebuild)
            build_target
            printf "[SHELL] Rebuilt (%s -> %s): %s\n\n" "$os_type" "$os_folder" "$target_abs"
            "$target_abs"
            ;;
        *)
            printf "[SHELL] Usage: %s {build|run|clean|rebuild}\n" "$0"
            exit 1
            ;;
    esac
}
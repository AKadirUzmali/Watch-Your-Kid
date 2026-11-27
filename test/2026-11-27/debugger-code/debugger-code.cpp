// Abdulkadir U. - 2026/11/27

// Debugger
#define __DEBUGGER_T_DEV__
#define __DEBUGGER_CSEL_20261127DEBUGGER 20261127
#define __DEBUGGER_CSEL_20261127FAKE 12345678

// Include
#include <iostream>
#include <format>
#include <string>
#include <cstdint>

#include <dev/debugger/debugger.hpp>

// Import
import core.time;
import core.sys.hardware.os;

// Using Namespace
using namespace core;
using namespace core::sys::hardware;

// Main
int main()
{
    // test kodunu listeye ekle
    DEBUGGER_ADD_CODE(__DEBUGGER_CSEL_20261127DEBUGGER);

    // testi başlat
    DEBUGGER(__DEBUGGER_CSEL_20261127DEBUGGER, std::cout << std::format("Arch: {}\n", os::get_name_arch()));

    // sahte kod testi
    DEBUGGER(__DEBUGGER_CSEL_20261127FAKE, std::cout << std::format("Timestamp: {}\n", time::get_timestamp()));

    // tekrar dene gerçek kod ile
    DEBUGGER(__DEBUGGER_CSEL_20261127DEBUGGER, std::cout << std::format("Timestamp: {}\n", time::get_timestamp()));

    // hata ayıklayıcı kodunu silsin
    DEBUGGER_DEL_CODE(__DEBUGGER_CSEL_20261127DEBUGGER);

    // hepsini tekrarla farklı şekilde, çıktı vermeyecekler
    DEBUGGER(__DEBUGGER_CSEL_20261127DEBUGGER, std::cout << std::format("Version: {}\n", os::get_version()));
    DEBUGGER(__DEBUGGER_CSEL_20261127FAKE, std::cout << std::format("Date: {}\n", time::get_date()));
    DEBUGGER(__DEBUGGER_CSEL_20261127DEBUGGER, std::cout << std::format("Date: {}\n", time::get_date()));

    return 0;
}
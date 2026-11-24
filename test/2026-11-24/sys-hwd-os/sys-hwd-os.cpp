// Abdulkadir U. - 2026/11/24

// Include
#include <iostream>
#include <format>
#include <string>

import core.sys.hardware.os;

// Using Namespace
using namespace core::sys::hardware;

// Main
int main()
{
    std::cout << std::format("Arch: {}\n", os::get_name_arch());
    std::cout << std::format("Platform: {}\n", os::get_name_platform());
    std::cout << std::format("Os: {}\n", os::get_name_os());
    std::cout << std::format("Version: {}\n", os::get_version());
}
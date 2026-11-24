// Abdulkadir U. - 2026/11/24

// Include
#include <iostream>
#include <format>
#include <string>

// Import
import core.time;

// Using Namespace
using namespace core;

// Main
int main()
{
    std::cout << std::format("Date: {}\n", time::get_date());
    std::cout << std::format("Time: {}\n", time::get_time());
    std::cout << std::format("Timestamp: {}\n", time::get_timestamp());
}
// Abdulkadir U. - 2026/11/23

// Import
#include <iostream>
#include <format>
#include <string>

import Expect;
import Assert;

// Main
int main() noexcept
{
    // expect_eq ve expect_noteq
    std::cout << std::format("expect_eq 1 = 1: {}\n", dev::test::expect_eq(1, 1));
    std::cout << std::format("expect_noteq 2 = 1: {}\n", dev::test::expect_noteq(2, 1));

    // assert_eq
    dev::test::assert_eq(1, 1);
    std::cout << std::format("assert_eq 1 = 1: true\n");

    // assert_noteq
    dev::test::assert_noteq(2, 1);
    std::cout << std::format("assert_noteq 2 = 1: true\n");
}
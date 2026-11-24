// Abdulkadir U. - 2026/11/23

// Include
#include <iostream>
#include <format>
#include <string>

// Import
import dev.test.expect;
import dev.test.assert;

// Using Namespace
using namespace dev::test;

// Main
int main() noexcept
{
    // expect_eq ve expect_noteq
    std::cout << std::format("expect_eq 1 = 1: {}\n", expect::expect_eq(1, 1));
    std::cout << std::format("expect_noteq 2 = 1: {}\n", expect::expect_noteq(2, 1));

    // assert_eq
    assert::assert_eq(1, 1);
    std::cout << std::format("assert_eq 1 = 1: true\n");

    // assert_noteq
    assert::assert_noteq(2, 1);
    std::cout << std::format("assert_noteq 2 = 1: true\n");
}
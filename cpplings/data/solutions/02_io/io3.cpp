// `std::cin` reads formatted input. When reading into an int, it parses digits.

#include "cpplings_test.hpp"
#include <string>

int parse_int(const std::string& text) {
    return std::stoi(text);
}

CPPLINGS_TEST(parses_numbers) {
    CPPLINGS_ASSERT_EQ(parse_int("42"), 42);
    CPPLINGS_ASSERT_EQ(parse_int("100"), 100);
}

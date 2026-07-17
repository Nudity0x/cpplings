// `std::cin` reads formatted input. When reading into an int, it parses digits.
//
// TODO: This exercise simulates input handling with a helper. Fix `parse_int`
// so it returns the integer value of the digits in the string. Use
// std::stoi to convert. The test passes strings and checks the parsed value.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <string>

int parse_int(const std::string& text) {
    // TODO: convert `text` to an int and return it.
    return 0;
}

CPPLINGS_TEST(parses_numbers) {
    CPPLINGS_ASSERT_EQ(parse_int("42"), 42);
    CPPLINGS_ASSERT_EQ(parse_int("100"), 100);
}

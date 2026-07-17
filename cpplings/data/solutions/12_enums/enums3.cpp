// A `switch` over an enum is a clean way to map each value to a result.

#include "cpplings_test.hpp"
#include <string>

enum class Color { Red, Green, Blue };

std::string to_string(Color c) {
    switch (c) {
        case Color::Red:
            return "red";
        case Color::Green:
            return "green";
        case Color::Blue:
            return "blue";
        default:
            return "unknown";
    }
}

CPPLINGS_TEST(color_names) {
    CPPLINGS_ASSERT_EQ(to_string(Color::Red), std::string("red"));
    CPPLINGS_ASSERT_EQ(to_string(Color::Green), std::string("green"));
    CPPLINGS_ASSERT_EQ(to_string(Color::Blue), std::string("blue"));
}

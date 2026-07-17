// A `switch` over an enum is a clean way to map each value to a result. The
// compiler can even warn if you forget a case.
//
// TODO: Complete the `switch` in `to_string` so each Color returns its name:
// Red -> "red", Green -> "green", Blue -> "blue".
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <string>

enum class Color { Red, Green, Blue };

std::string to_string(Color c) {
    switch (c) {
        // TODO: add a case for each color returning the right string.
        default:
            return "unknown";
    }
}

CPPLINGS_TEST(color_names) {
    CPPLINGS_ASSERT_EQ(to_string(Color::Red), std::string("red"));
    CPPLINGS_ASSERT_EQ(to_string(Color::Green), std::string("green"));
    CPPLINGS_ASSERT_EQ(to_string(Color::Blue), std::string("blue"));
}

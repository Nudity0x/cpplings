// An `enum class` defines a set of named values.

#include "cpplings_test.hpp"

enum class Color {
    Red,
    Green,
    Blue,
};

Color favorite() {
    return Color::Blue;
}

CPPLINGS_TEST(has_blue) {
    CPPLINGS_ASSERT(favorite() == Color::Blue);
}

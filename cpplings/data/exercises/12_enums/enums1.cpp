// An `enum class` defines a set of named values.
//
// TODO: Add a `Blue` value to the enum and return it from favorite() so the
// test passes.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

enum class Color {
    Red,
    Green,
};

Color favorite() {
    return Color::Red;  // TODO: return Blue
}

CPPLINGS_TEST(has_blue) {
    CPPLINGS_ASSERT(favorite() == Color::Blue);
}

// A lambda is an inline anonymous function: [](int x) { return x + 1; }.
// You can store one in a variable and call it like any function.
//
// TODO: Define a lambda named `square` that takes an int and returns its
// square. The test calls it with a few values.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

CPPLINGS_TEST(basic_lambda) {
    // TODO: replace the line below with a lambda taking an int, returning n*n.
    auto square = 0;

    CPPLINGS_ASSERT_EQ(square(3), 9);
    CPPLINGS_ASSERT_EQ(square(5), 25);
}

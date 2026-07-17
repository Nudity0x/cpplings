// Functions declare a return type, a name, and parameters.
//
// TODO: Write a function `square` that takes an int and returns its square.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

// TODO: define int square(int n)

CPPLINGS_TEST(square_works) {
    CPPLINGS_ASSERT_EQ(square(4), 16);
    CPPLINGS_ASSERT_EQ(square(-3), 9);
}

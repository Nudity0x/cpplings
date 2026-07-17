// Functions declare a return type, a name, and parameters.

#include "cpplings_test.hpp"

int square(int n) {
    return n * n;
}

CPPLINGS_TEST(square_works) {
    CPPLINGS_ASSERT_EQ(square(4), 16);
    CPPLINGS_ASSERT_EQ(square(-3), 9);
}

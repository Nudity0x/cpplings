// Function parameters have types, and the call must match.

#include "cpplings_test.hpp"

int add(int a, int b) {
    return a + b;
}

CPPLINGS_TEST(add_works) {
    CPPLINGS_ASSERT_EQ(add(2, 3), 5);
}

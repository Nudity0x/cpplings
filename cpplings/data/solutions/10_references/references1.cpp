// A reference is an alias for another variable.

#include "cpplings_test.hpp"

void increment(int& n) {
    n = n + 1;
}

CPPLINGS_TEST(by_reference) {
    int x = 10;
    increment(x);
    CPPLINGS_ASSERT_EQ(x, 11);
}

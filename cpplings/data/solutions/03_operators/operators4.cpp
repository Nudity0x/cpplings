// The modulo operator `%` gives the remainder of integer division.

#include "cpplings_test.hpp"

bool is_even(int n) {
    return n % 2 == 0;
}

CPPLINGS_TEST(evenness) {
    CPPLINGS_ASSERT(is_even(4));
    CPPLINGS_ASSERT(is_even(0));
    CPPLINGS_ASSERT_FALSE(is_even(7));
}

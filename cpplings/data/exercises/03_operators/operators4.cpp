// The modulo operator `%` gives the remainder of integer division.
//
// TODO: Fix `is_even` so it returns true when `n` is even. A number is even
// when it leaves no remainder after division by 2.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

bool is_even(int n) {
    // TODO: use the modulo operator to test evenness.
    return n % 2 == 1;
}

CPPLINGS_TEST(evenness) {
    CPPLINGS_ASSERT(is_even(4));
    CPPLINGS_ASSERT(is_even(0));
    CPPLINGS_ASSERT_FALSE(is_even(7));
}

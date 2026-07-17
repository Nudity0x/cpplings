// The ternary operator `cond ? a : b` is a compact if/else expression.
//
// TODO: Fix `max_of` so it returns the larger of the two arguments using the
// ternary operator.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

int max_of(int a, int b) {
    // TODO: return the larger value.
    return a < b ? a : b;
}

CPPLINGS_TEST(picks_max) {
    CPPLINGS_ASSERT_EQ(max_of(3, 9), 9);
    CPPLINGS_ASSERT_EQ(max_of(9, 3), 9);
    CPPLINGS_ASSERT_EQ(max_of(5, 5), 5);
}

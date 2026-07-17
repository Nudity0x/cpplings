// The ternary operator `cond ? a : b` is a compact if/else expression.

#include "cpplings_test.hpp"

CPPLINGS_TEST(pick_larger) {
    int a = 8;
    int b = 12;
    int larger = a > b ? a : b;
    CPPLINGS_ASSERT_EQ(larger, 12);
}

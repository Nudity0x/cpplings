// The ternary operator `cond ? a : b` is a compact if/else expression.
//
// TODO: Use a ternary to set `larger` to the greater of a and b.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

CPPLINGS_TEST(pick_larger) {
    int a = 8;
    int b = 12;
    int larger = 0;  // TODO: a > b ? ... : ...
    CPPLINGS_ASSERT_EQ(larger, 12);
}

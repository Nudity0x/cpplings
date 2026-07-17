// Integer types have different sizes. `int` is typically 4 bytes.
//
// TODO: Fix the declared type so `count` holds the value 300 correctly and the
// test passes. (Hint: a plain `char` cannot hold 300.)
//
// I AM NOT DONE

#include "cpplings_test.hpp"

CPPLINGS_TEST(count_holds_300) {
    char count = 300;
    CPPLINGS_ASSERT_EQ(static_cast<int>(count), 300);
}

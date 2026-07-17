// A `while` loop runs as long as its condition is true.
//
// TODO: Fix `count_digits` so it returns how many decimal digits `n` has.
// Repeatedly divide by 10 until the number reaches 0. Assume n > 0.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

int count_digits(int n) {
    int digits = 0;
    // TODO: loop, dividing n by 10 each time, counting steps.
    return digits;
}

CPPLINGS_TEST(counts_digits) {
    CPPLINGS_ASSERT_EQ(count_digits(5), 1);
    CPPLINGS_ASSERT_EQ(count_digits(42), 2);
    CPPLINGS_ASSERT_EQ(count_digits(1000), 4);
}

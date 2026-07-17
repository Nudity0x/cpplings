// A `for` loop repeats a block a fixed number of times.
//
// TODO: Fix the loop so it sums the integers 1..=5 (inclusive). The test
// expects 15. Check the loop bounds.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

CPPLINGS_TEST(sum_1_to_5) {
    int sum = 0;
    for (int i = 1; i < 5; ++i) {
        sum += i;
    }
    CPPLINGS_ASSERT_EQ(sum, 15);
}

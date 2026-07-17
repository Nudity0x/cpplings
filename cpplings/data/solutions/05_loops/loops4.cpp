// A `while` loop runs as long as its condition is true.

#include "cpplings_test.hpp"

int count_digits(int n) {
    int digits = 0;
    while (n > 0) {
        n /= 10;
        ++digits;
    }
    return digits;
}

CPPLINGS_TEST(counts_digits) {
    CPPLINGS_ASSERT_EQ(count_digits(5), 1);
    CPPLINGS_ASSERT_EQ(count_digits(42), 2);
    CPPLINGS_ASSERT_EQ(count_digits(1000), 4);
}

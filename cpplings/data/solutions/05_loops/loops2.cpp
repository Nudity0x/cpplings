// A `while` loop repeats while its condition is true.

#include "cpplings_test.hpp"

CPPLINGS_TEST(halvings_of_100) {
    int n = 100;
    int steps = 0;
    while (n > 0) {
        n = n / 2;
        ++steps;
    }
    CPPLINGS_ASSERT_EQ(steps, 7);
}

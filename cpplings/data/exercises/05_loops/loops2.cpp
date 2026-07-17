// A `while` loop repeats while its condition is true.
//
// TODO: Complete the loop so it counts how many times 100 can be halved with
// integer division before reaching 0. The test expects 7.
// (100 -> 50 -> 25 -> 12 -> 6 -> 3 -> 1 -> 0 is 7 steps.)
//
// I AM NOT DONE

#include "cpplings_test.hpp"

CPPLINGS_TEST(halvings_of_100) {
    int n = 100;
    int steps = 0;
    while (/* TODO: condition */ false) {
        n = n / 2;
        ++steps;
    }
    CPPLINGS_ASSERT_EQ(steps, 7);
}

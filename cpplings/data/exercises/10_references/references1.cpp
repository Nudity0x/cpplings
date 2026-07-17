// A reference is an alias for another variable. Changes through it affect the
// original. Passing by reference (&) lets a function modify its caller's value.
//
// TODO: Make `increment` take its parameter by reference so the caller's
// variable is actually changed.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

void increment(int n) {
    n = n + 1;
}

CPPLINGS_TEST(by_reference) {
    int x = 10;
    increment(x);
    CPPLINGS_ASSERT_EQ(x, 11);
}

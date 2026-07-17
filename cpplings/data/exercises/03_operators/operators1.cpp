// Arithmetic operators: + - * / %. Integer division truncates.
//
// TODO: Fix the expression so `half` equals 5 (integer division of 11 by 2 is
// 5, but the test wants exactly 5 — check the operator).
//
// I AM NOT DONE

#include "cpplings_test.hpp"

CPPLINGS_TEST(half_of_10) {
    int n = 10;
    int half = n * 2;
    CPPLINGS_ASSERT_EQ(half, 5);
}

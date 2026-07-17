// Arithmetic operators: + - * / %. Integer division truncates.

#include "cpplings_test.hpp"

CPPLINGS_TEST(half_of_10) {
    int n = 10;
    int half = n / 2;
    CPPLINGS_ASSERT_EQ(half, 5);
}

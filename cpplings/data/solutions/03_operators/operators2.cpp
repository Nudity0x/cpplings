// The modulo operator % gives the remainder of integer division.

#include "cpplings_test.hpp"

CPPLINGS_TEST(remainder_of_17_by_5) {
    int rem = 17 % 5;
    CPPLINGS_ASSERT_EQ(rem, 2);
}

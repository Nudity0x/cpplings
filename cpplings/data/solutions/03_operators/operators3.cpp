// Comparison operators return bool. && is logical AND, || is logical OR.

#include "cpplings_test.hpp"

CPPLINGS_TEST(five_is_in_range) {
    int n = 5;
    bool in_range = n >= 1 && n <= 10;
    CPPLINGS_ASSERT(in_range);

    int m = 20;
    bool m_in_range = m >= 1 && m <= 10;
    CPPLINGS_ASSERT_FALSE(m_in_range);
}

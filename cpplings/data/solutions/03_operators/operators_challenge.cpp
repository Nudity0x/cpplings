#include "cpplings_test.hpp"

bool is_leap_year(int year) {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

CPPLINGS_TEST(detects_leap_years) {
    CPPLINGS_ASSERT(is_leap_year(2000));
    CPPLINGS_ASSERT(is_leap_year(2024));
    CPPLINGS_ASSERT_FALSE(is_leap_year(1900));
    CPPLINGS_ASSERT_FALSE(is_leap_year(2023));
}

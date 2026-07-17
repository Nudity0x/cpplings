#include "cpplings_test.hpp"

int to_int(double value) {
    return static_cast<int>(value);
}

CPPLINGS_TEST(truncates_to_int) {
    CPPLINGS_ASSERT_EQ(to_int(3.9), 3);
    CPPLINGS_ASSERT_EQ(to_int(7.2), 7);
    CPPLINGS_ASSERT_EQ(to_int(-4.8), -4);
}

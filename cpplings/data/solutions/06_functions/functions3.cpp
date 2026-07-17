// Default arguments let a caller omit trailing parameters.

#include "cpplings_test.hpp"

int greet_count(int base, int times = 1) {
    return base * times;
}

CPPLINGS_TEST(defaults) {
    CPPLINGS_ASSERT_EQ(greet_count(5), 5);
    CPPLINGS_ASSERT_EQ(greet_count(5, 3), 15);
}

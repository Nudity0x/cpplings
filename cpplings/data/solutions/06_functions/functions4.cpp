// Functions can have default arguments, used when the caller omits them.

#include "cpplings_test.hpp"

int greet_count(int base, int times = 1) {
    return base * times;
}

CPPLINGS_TEST(default_argument) {
    CPPLINGS_ASSERT_EQ(greet_count(5), 5);
    CPPLINGS_ASSERT_EQ(greet_count(5, 3), 15);
}

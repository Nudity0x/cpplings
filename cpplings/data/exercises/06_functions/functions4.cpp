// Functions can have default arguments, used when the caller omits them.
//
// TODO: Give `greet_count` a default of 1 for its `times` parameter so the
// first assertion (which omits it) passes, while explicit calls still work.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

int greet_count(int base, int times) {
    return base * times;
}

CPPLINGS_TEST(default_argument) {
    CPPLINGS_ASSERT_EQ(greet_count(5), 5);
    CPPLINGS_ASSERT_EQ(greet_count(5, 3), 15);
}

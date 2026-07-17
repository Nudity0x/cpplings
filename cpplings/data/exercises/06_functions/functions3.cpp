// Default arguments let a caller omit trailing parameters.
//
// TODO: Give `greet_count` a default of 1 for its `times` parameter so the
// first assertion (calling with one argument) compiles and passes.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

int greet_count(int base, int times) {
    return base * times;
}

CPPLINGS_TEST(defaults) {
    CPPLINGS_ASSERT_EQ(greet_count(5), 5);
    CPPLINGS_ASSERT_EQ(greet_count(5, 3), 15);
}

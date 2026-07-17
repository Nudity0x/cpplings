// `const` marks a value that must not change.

#include "cpplings_test.hpp"

CPPLINGS_TEST(max_is_100) {
    const int max = 100;
    CPPLINGS_ASSERT_EQ(max, 100);
}

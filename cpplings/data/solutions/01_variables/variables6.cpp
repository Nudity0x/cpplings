// Uninitialized local variables hold garbage. Always initialize.

#include "cpplings_test.hpp"

CPPLINGS_TEST(score_starts_at_zero) {
    int score = 0;
    CPPLINGS_ASSERT_EQ(score, 0);
}

// Uninitialized local variables hold garbage. Always initialize.
//
// TODO: `score` is declared but never given a value, then read. Initialize it
// to 0 so the test is deterministic and passes.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

CPPLINGS_TEST(score_starts_at_zero) {
    int score;
    CPPLINGS_ASSERT_EQ(score, 0);
}

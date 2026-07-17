// A lambda can *capture* variables from its surrounding scope. `[=]` captures
// by copy, `[&]` by reference, or name specific variables: `[factor]`.
//
// TODO: Make the lambda `scale` capture `factor` by value so it multiplies its
// argument by the current factor. Fix the capture list. The test sets a factor
// then calls the lambda.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

CPPLINGS_TEST(capture_by_value) {
    int factor = 10;

    // TODO: fix the capture list so `factor` is usable inside the lambda.
    auto scale = [](int x) { return x * factor; };

    CPPLINGS_ASSERT_EQ(scale(3), 30);
    CPPLINGS_ASSERT_EQ(scale(7), 70);
}

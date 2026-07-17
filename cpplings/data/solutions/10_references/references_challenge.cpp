#include "cpplings_test.hpp"

bool clamp_into(const int& value, int low, int high, int& out) {
    if (value < low) {
        out = low;
        return true;
    }
    if (value > high) {
        out = high;
        return true;
    }
    out = value;
    return false;
}

CPPLINGS_TEST(clamps_and_reports) {
    int out = 0;

    CPPLINGS_ASSERT(clamp_into(15, 0, 10, out));
    CPPLINGS_ASSERT_EQ(out, 10);

    CPPLINGS_ASSERT(clamp_into(-3, 0, 10, out));
    CPPLINGS_ASSERT_EQ(out, 0);

    CPPLINGS_ASSERT_FALSE(clamp_into(5, 0, 10, out));
    CPPLINGS_ASSERT_EQ(out, 5);
}

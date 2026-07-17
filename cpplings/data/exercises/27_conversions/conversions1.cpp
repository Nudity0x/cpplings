// C++ converts between numeric types with static_cast<T>(value). This makes an
// intentional conversion explicit and visible, unlike a silent implicit one.
// Converting a double to int truncates toward zero (drops the fraction).
//
// TODO: `to_int` should convert the double to an int using static_cast and
// return it. Complete it. The test checks truncation on a few values.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

int to_int(double value) {
    // TODO: return value converted to int with static_cast.
    return 0;
}

CPPLINGS_TEST(truncates_to_int) {
    CPPLINGS_ASSERT_EQ(to_int(3.9), 3);
    CPPLINGS_ASSERT_EQ(to_int(7.2), 7);
    CPPLINGS_ASSERT_EQ(to_int(-4.8), -4);
}

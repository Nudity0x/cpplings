// CHALLENGE — references (binding, pass-by-reference, const ref).
//
// Builds on: functions (06), conditionals (04).
//
// Challenges are the last, hardest exercise in a section: longer, and they pull
// the section together while reusing earlier topics.
//
// TODO: `clamp_into` takes a value by const reference and a low/high bound, and
// writes the clamped result into `out` (passed by reference). Clamping means:
//   - if value < low  -> out = low
//   - if value > high -> out = high
//   - otherwise       -> out = value
// Return true if the value had to be clamped (was out of range), false if it
// was already within [low, high]. This mixes an out-parameter (reference) with
// a bool return.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

bool clamp_into(const int& value, int low, int high, int& out) {
    // TODO: set `out` to the clamped value and return whether clamping happened.
    return false;
}

CPPLINGS_TEST(clamps_and_reports) {
    int out = 0;

    CPPLINGS_ASSERT(clamp_into(15, 0, 10, out));   // above high
    CPPLINGS_ASSERT_EQ(out, 10);

    CPPLINGS_ASSERT(clamp_into(-3, 0, 10, out));    // below low
    CPPLINGS_ASSERT_EQ(out, 0);

    CPPLINGS_ASSERT_FALSE(clamp_into(5, 0, 10, out)); // in range
    CPPLINGS_ASSERT_EQ(out, 5);
}

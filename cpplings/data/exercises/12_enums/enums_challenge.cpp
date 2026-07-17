// CHALLENGE — enums (plain and scoped enums, switch on enum).
//
// Builds on: conditionals (04), functions (06), structs (11).
//
// Challenges are the last, hardest exercise in a section: longer, and they pull
// the section together while reusing earlier topics.
//
// TODO: A tiny state machine for a traffic light. Given the current `Light` and
// implement `next` to return the light that follows:
//   Green -> Yellow -> Red -> Green (cycle).
// Also implement `go_duration` returning how many seconds each light lasts:
//   Green 30, Yellow 5, Red 25.
// Use a `switch` on the scoped enum in both functions.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

enum class Light {
    Green,
    Yellow,
    Red,
};

Light next(Light current) {
    // TODO: switch on current and return the next light in the cycle.
    return current;
}

int go_duration(Light light) {
    // TODO: switch on light and return its duration in seconds.
    return 0;
}

CPPLINGS_TEST(traffic_light_cycle) {
    CPPLINGS_ASSERT(next(Light::Green) == Light::Yellow);
    CPPLINGS_ASSERT(next(Light::Yellow) == Light::Red);
    CPPLINGS_ASSERT(next(Light::Red) == Light::Green);

    CPPLINGS_ASSERT_EQ(go_duration(Light::Green), 30);
    CPPLINGS_ASSERT_EQ(go_duration(Light::Yellow), 5);
    CPPLINGS_ASSERT_EQ(go_duration(Light::Red), 25);
}

#include "cpplings_test.hpp"

enum class Light {
    Green,
    Yellow,
    Red,
};

Light next(Light current) {
    switch (current) {
        case Light::Green:
            return Light::Yellow;
        case Light::Yellow:
            return Light::Red;
        case Light::Red:
            return Light::Green;
    }
    return current;
}

int go_duration(Light light) {
    switch (light) {
        case Light::Green:
            return 30;
        case Light::Yellow:
            return 5;
        case Light::Red:
            return 25;
    }
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

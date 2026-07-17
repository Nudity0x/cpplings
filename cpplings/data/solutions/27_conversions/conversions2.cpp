#include "cpplings_test.hpp"

struct Meters {
    int value;
    Meters(int v) : value(v) {}
};

int total_meters(Meters a, Meters b) {
    return a.value + b.value;
}

CPPLINGS_TEST(converting_constructor) {
    Meters explicit_m(10);
    CPPLINGS_ASSERT_EQ(explicit_m.value, 10);

    CPPLINGS_ASSERT_EQ(total_meters(3, 4), 7);
}

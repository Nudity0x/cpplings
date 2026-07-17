// A single-argument constructor doubles as a *converting constructor*: it lets
// the compiler build your type from that argument type. `Meters m = 5;` works if
// Meters has a constructor taking an int.
//
// TODO: Give `Meters` a constructor taking an int number of meters and storing
// it in `value`. This also enables converting an int to Meters. The test builds
// a Meters both explicitly and via conversion.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

struct Meters {
    int value;
    // TODO: add a constructor taking an int and setting value.
};

int total_meters(Meters a, Meters b) {
    return a.value + b.value;
}

CPPLINGS_TEST(converting_constructor) {
    Meters explicit_m(10);
    CPPLINGS_ASSERT_EQ(explicit_m.value, 10);

    // An int converts to Meters through the constructor.
    CPPLINGS_ASSERT_EQ(total_meters(3, 4), 7);
}

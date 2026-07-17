// A class can define how it converts *to* another type with a conversion
// operator: `operator int() const { return ...; }`. Marking it `explicit` means
// the conversion only happens with an explicit cast, not silently.
//
// TODO: Give `Fahrenheit` a conversion operator to `double` that returns its
// stored `degrees`. The test reads the temperature through the conversion.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

struct Fahrenheit {
    double degrees;
    Fahrenheit(double d) : degrees(d) {}
    // TODO: add `operator double() const` returning degrees.
};

CPPLINGS_TEST(conversion_operator) {
    Fahrenheit temp(98.6);
    double as_double = temp;  // uses the conversion operator
    CPPLINGS_ASSERT(as_double > 98.5 && as_double < 98.7);
}

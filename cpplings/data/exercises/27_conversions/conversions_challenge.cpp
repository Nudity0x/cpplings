// CHALLENGE — conversions (a value type with explicit, safe conversions).
//
// Builds on: classes (14), operator overloading (20), functions (06).
//
// Challenges are the last, hardest exercise in a section: longer, and they pull
// the section together while reusing earlier topics.
//
// TODO: A `Celsius` temperature type that converts cleanly and guards its
// invariants:
//   1. Construct from a double (degrees Celsius).
//   2. Give it an EXPLICIT `operator double() const` returning the stored
//      degrees — explicit so it never converts silently in arithmetic.
//   3. Add a member `to_fahrenheit()` returning a `Fahrenheit` (defined below):
//      F = C * 9 / 5 + 32.
//   4. `Fahrenheit` mirrors it: construct from a double, explicit
//      `operator double() const`.
// Make the test below read like ordinary temperature conversion.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

struct Fahrenheit {
    double degrees;
    // TODO: construct from a double.
    // TODO: explicit operator double() const;
};

struct Celsius {
    double degrees;
    // TODO: construct from a double.
    // TODO: explicit operator double() const;
    // TODO: Fahrenheit to_fahrenheit() const;
};

CPPLINGS_TEST(celsius_converts_to_fahrenheit) {
    Celsius boiling(100.0);
    // Explicit conversion required — static_cast, not implicit.
    double c = static_cast<double>(boiling);
    CPPLINGS_ASSERT(c > 99.9 && c < 100.1);

    Fahrenheit f = boiling.to_fahrenheit();
    double fv = static_cast<double>(f);
    CPPLINGS_ASSERT(fv > 211.9 && fv < 212.1);

    Celsius freezing(0.0);
    double frz = static_cast<double>(freezing.to_fahrenheit());
    CPPLINGS_ASSERT(frz > 31.9 && frz < 32.1);
}

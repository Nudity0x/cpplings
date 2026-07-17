#include "cpplings_test.hpp"

struct Fahrenheit {
    double degrees;
    Fahrenheit(double d) : degrees(d) {}
    operator double() const { return degrees; }
};

CPPLINGS_TEST(conversion_operator) {
    Fahrenheit temp(98.6);
    double as_double = temp;  // uses the conversion operator
    CPPLINGS_ASSERT(as_double > 98.5 && as_double < 98.7);
}

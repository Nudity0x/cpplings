#include "cpplings_test.hpp"

struct Fahrenheit {
    double degrees;
    explicit Fahrenheit(double d) : degrees(d) {}
    explicit operator double() const { return degrees; }
};

struct Celsius {
    double degrees;
    explicit Celsius(double d) : degrees(d) {}
    explicit operator double() const { return degrees; }
    Fahrenheit to_fahrenheit() const {
        return Fahrenheit(degrees * 9.0 / 5.0 + 32.0);
    }
};

CPPLINGS_TEST(celsius_converts_to_fahrenheit) {
    Celsius boiling(100.0);
    double c = static_cast<double>(boiling);
    CPPLINGS_ASSERT(c > 99.9 && c < 100.1);

    Fahrenheit f = boiling.to_fahrenheit();
    double fv = static_cast<double>(f);
    CPPLINGS_ASSERT(fv > 211.9 && fv < 212.1);

    Celsius freezing(0.0);
    double frz = static_cast<double>(freezing.to_fahrenheit());
    CPPLINGS_ASSERT(frz > 31.9 && frz < 32.1);
}

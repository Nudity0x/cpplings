// Operator overloading lets your types work with built-in operators like + and
// ==. An overloaded operator is just a function with a special name:
// `Type operator+(const Type& other) const { ... }`.
//
// TODO: Give `Vec2` an `operator+` that adds two vectors component-wise and
// returns the result. The test adds two Vec2 values and checks x and y.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

struct Vec2 {
    int x;
    int y;

    // TODO: implement operator+ returning a Vec2 whose components are the sums.
};

CPPLINGS_TEST(vec_addition) {
    Vec2 a{1, 2};
    Vec2 b{3, 4};
    Vec2 c = a + b;
    CPPLINGS_ASSERT_EQ(c.x, 4);
    CPPLINGS_ASSERT_EQ(c.y, 6);
}

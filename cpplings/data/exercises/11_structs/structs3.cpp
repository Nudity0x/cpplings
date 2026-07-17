// Structs can have member functions, not just data. A member function has
// access to the struct's fields through `this`.
//
// TODO: Add a member function `area()` to `Rectangle` that returns width *
// height so the test passes.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

struct Rectangle {
    int width;
    int height;

    // TODO: add an `int area() const` member function here.
};

CPPLINGS_TEST(rectangle_area) {
    Rectangle r{4, 5};
    CPPLINGS_ASSERT_EQ(r.area(), 20);
}

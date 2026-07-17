// A derived class constructor must initialize its base class by calling the
// base constructor in its initializer list: `Derived(args) : Base(x) { ... }`.
//
// TODO: `Square` should pass its side length to the `Shape` base constructor so
// `width` and `height` are both set to `side`. Fix the initializer list.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

class Shape {
public:
    int width;
    int height;
    Shape(int w, int h) : width(w), height(h) {}
    int area() const { return width * height; }
};

class Square : public Shape {
public:
    // TODO: call the Shape constructor with side for both width and height.
    Square(int side) {}
};

CPPLINGS_TEST(square_area) {
    Square s(5);
    CPPLINGS_ASSERT_EQ(s.area(), 25);
}

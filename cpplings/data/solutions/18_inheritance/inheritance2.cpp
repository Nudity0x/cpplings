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
    Square(int side) : Shape(side, side) {}
};

CPPLINGS_TEST(square_area) {
    Square s(5);
    CPPLINGS_ASSERT_EQ(s.area(), 25);
}

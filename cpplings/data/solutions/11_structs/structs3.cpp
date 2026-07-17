// Structs can have member functions, not just data.

#include "cpplings_test.hpp"

struct Rectangle {
    int width;
    int height;

    int area() const {
        return width * height;
    }
};

CPPLINGS_TEST(rectangle_area) {
    Rectangle r{4, 5};
    CPPLINGS_ASSERT_EQ(r.area(), 20);
}

// Structs can have member functions too.
//
// TODO: Implement `area()` so it returns width * height.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

struct Rectangle {
    int width;
    int height;

    int area() const {
        return 0;  // TODO: return width * height
    }
};

CPPLINGS_TEST(rect_area) {
    Rectangle r{4, 5};
    CPPLINGS_ASSERT_EQ(r.area(), 20);
}

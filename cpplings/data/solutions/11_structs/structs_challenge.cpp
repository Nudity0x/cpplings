#include "cpplings_test.hpp"

struct Rectangle {
    int width;
    int height;
};

int area(const Rectangle& r) {
    return r.width * r.height;
}

int total_area(const Rectangle* rects, int count) {
    int sum = 0;
    for (int i = 0; i < count; ++i) {
        sum += area(rects[i]);
    }
    return sum;
}

CPPLINGS_TEST(struct_area_and_total) {
    Rectangle a{3, 4};
    CPPLINGS_ASSERT_EQ(area(a), 12);

    Rectangle shapes[] = {{2, 2}, {3, 5}, {1, 10}};
    CPPLINGS_ASSERT_EQ(total_area(shapes, 3), 4 + 15 + 10);
}

#include "cpplings_test.hpp"

struct Point {
    int x;
    int y;

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

CPPLINGS_TEST(point_equality) {
    Point a{2, 3};
    Point b{2, 3};
    Point c{2, 9};

    CPPLINGS_ASSERT(a == b);
    CPPLINGS_ASSERT_FALSE(a == c);
}

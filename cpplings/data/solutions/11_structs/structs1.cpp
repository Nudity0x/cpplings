// A struct groups related data under one type.

#include "cpplings_test.hpp"

struct Point {
    int x;
    int y;
};

CPPLINGS_TEST(point_members) {
    Point p;
    p.x = 3;
    p.y = 4;
    CPPLINGS_ASSERT_EQ(p.x + p.y, 7);
}

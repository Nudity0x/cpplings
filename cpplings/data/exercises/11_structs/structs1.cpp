// A struct groups related data under one type.
//
// TODO: The struct is missing a `y` member. Add it (an int) so the test that
// reads point.y compiles and passes.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

struct Point {
    int x;
};

CPPLINGS_TEST(point_members) {
    Point p;
    p.x = 3;
    p.y = 4;
    CPPLINGS_ASSERT_EQ(p.x + p.y, 7);
}

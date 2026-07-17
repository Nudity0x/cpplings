// The equality operator `operator==` lets your type be compared with ==. It
// takes the other object and returns bool. C++ does NOT generate it for you in
// C++17, so you must write it when you need value comparison.
//
// TODO: Give `Point` an `operator==` that returns true when both coordinates
// match. The test compares equal and unequal points.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

struct Point {
    int x;
    int y;

    // TODO: implement operator== comparing both x and y.
};

CPPLINGS_TEST(point_equality) {
    Point a{2, 3};
    Point b{2, 3};
    Point c{2, 9};

    CPPLINGS_ASSERT(a == b);
    CPPLINGS_ASSERT_FALSE(a == c);
}

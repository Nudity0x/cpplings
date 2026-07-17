// CHALLENGE — structs (aggregate types, members, functions on structs).
//
// Builds on: functions (06), loops (05), arrays (07), references (10).
//
// Challenges are the last, hardest exercise in a section: longer, and they pull
// the section together while reusing earlier topics.
//
// TODO: A `Rectangle` struct has `width` and `height`. Implement two free
// functions:
//   1. `area(const Rectangle&)` -> width * height.
//   2. `total_area(const Rectangle* rects, int count)` -> the summed area of an
//      array of rectangles, using area() in a loop.
// This combines structs with arrays, pointers, and a helper function.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

struct Rectangle {
    int width;
    int height;
};

int area(const Rectangle& r) {
    // TODO: return the rectangle's area.
    return 0;
}

int total_area(const Rectangle* rects, int count) {
    // TODO: sum area(rects[i]) for i in [0, count).
    return 0;
}

CPPLINGS_TEST(struct_area_and_total) {
    Rectangle a{3, 4};
    CPPLINGS_ASSERT_EQ(area(a), 12);

    Rectangle shapes[] = {{2, 2}, {3, 5}, {1, 10}};
    CPPLINGS_ASSERT_EQ(total_area(shapes, 3), 4 + 15 + 10);
}

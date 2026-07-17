// CHALLENGE — operator overloading (member vs free, arithmetic, comparison).
//
// Builds on: classes (14), references (10), functions (06).
//
// Challenges are the last, hardest exercise in a section: longer, and they pull
// the section together while reusing earlier topics.
//
// TODO: A 2D `Vec2` with int x, y. Give it a natural value-type interface by
// overloading operators:
//   1. `operator+`  : component-wise addition (as a free function or member).
//   2. `operator==` : true when both components match.
//   3. `operator*`  : scaling by an int on the RIGHT (v * k) — member is fine.
// Implement them so the test below reads like ordinary math.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

struct Vec2 {
    int x;
    int y;

    // TODO: Vec2 operator+(const Vec2& other) const;
    // TODO: bool operator==(const Vec2& other) const;
    // TODO: Vec2 operator*(int k) const;
};

CPPLINGS_TEST(vec2_operators) {
    Vec2 a{1, 2};
    Vec2 b{3, 4};

    Vec2 sum = a + b;
    CPPLINGS_ASSERT(sum == (Vec2{4, 6}));

    Vec2 scaled = a * 3;
    CPPLINGS_ASSERT(scaled == (Vec2{3, 6}));

    CPPLINGS_ASSERT_FALSE(a == b);
}

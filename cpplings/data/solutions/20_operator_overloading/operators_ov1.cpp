#include "cpplings_test.hpp"

struct Vec2 {
    int x;
    int y;

    Vec2 operator+(const Vec2& other) const {
        return Vec2{x + other.x, y + other.y};
    }
};

CPPLINGS_TEST(vec_addition) {
    Vec2 a{1, 2};
    Vec2 b{3, 4};
    Vec2 c = a + b;
    CPPLINGS_ASSERT_EQ(c.x, 4);
    CPPLINGS_ASSERT_EQ(c.y, 6);
}

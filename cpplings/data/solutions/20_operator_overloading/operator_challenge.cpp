#include "cpplings_test.hpp"

struct Vec2 {
    int x;
    int y;

    Vec2 operator+(const Vec2& other) const {
        return Vec2{x + other.x, y + other.y};
    }

    bool operator==(const Vec2& other) const {
        return x == other.x && y == other.y;
    }

    Vec2 operator*(int k) const {
        return Vec2{x * k, y * k};
    }
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

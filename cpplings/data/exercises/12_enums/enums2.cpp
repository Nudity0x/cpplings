// A switch over an enum lets you handle each case.
//
// TODO: Add the missing case for Direction::West returning -1 so the test
// passes.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

enum class Direction {
    East,
    West,
};

int delta(Direction d) {
    switch (d) {
        case Direction::East:
            return 1;
    }
    return 0;
}

CPPLINGS_TEST(west_is_negative) {
    CPPLINGS_ASSERT_EQ(delta(Direction::West), -1);
}

#include "cpplings_test.hpp"

struct Grid {
    int data[4] = {0, 0, 0, 0};

    int& operator[](int i) { return data[i]; }
};

CPPLINGS_TEST(grid_indexing) {
    Grid g;
    g[2] = 42;
    CPPLINGS_ASSERT_EQ(g[2], 42);
    CPPLINGS_ASSERT_EQ(g[0], 0);
}

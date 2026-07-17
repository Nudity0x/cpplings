// operator[] lets your type be indexed like an array. It usually returns a
// reference so callers can both read and write through it:
//   int& operator[](int i) { ... }
//
// TODO: Give `Grid` an operator[] that returns a reference to the element at
// index `i` in its `data` array. Returning a reference lets the test assign
// through it. The test writes and reads back a value.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

struct Grid {
    int data[4] = {0, 0, 0, 0};

    // TODO: implement operator[] returning a reference to data[i].
};

CPPLINGS_TEST(grid_indexing) {
    Grid g;
    g[2] = 42;
    CPPLINGS_ASSERT_EQ(g[2], 42);
    CPPLINGS_ASSERT_EQ(g[0], 0);
}

// A const reference lets a function read a big object without copying it,
// while promising not to modify it.
//
// TODO: Give `sum` a const reference parameter so it compiles without copying
// the vector, and returns the total.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <vector>

int sum(std::vector<int> values) {
    int total = 0;
    for (int v : values) {
        total += v;
    }
    return total;
}

CPPLINGS_TEST(const_ref) {
    std::vector<int> data = {1, 2, 3, 4};
    CPPLINGS_ASSERT_EQ(sum(data), 10);
}

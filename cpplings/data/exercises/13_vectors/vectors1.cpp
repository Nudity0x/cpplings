// std::vector is a dynamic array that grows as you push onto it.
//
// TODO: Push the value 3 onto the vector so it holds {1, 2, 3} and the test
// passes.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <vector>

CPPLINGS_TEST(push_back) {
    std::vector<int> v = {1, 2};
    // TODO: add 3
    CPPLINGS_ASSERT_EQ(static_cast<int>(v.size()), 3);
    CPPLINGS_ASSERT_EQ(v[2], 3);
}

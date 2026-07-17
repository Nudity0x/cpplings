// A function template works for many types with one definition.

#include "cpplings_test.hpp"

template <typename T>
T max_of(T a, T b) {
    return a > b ? a : b;
}

CPPLINGS_TEST(works_for_ints) {
    CPPLINGS_ASSERT_EQ(max_of(3, 7), 7);
}

CPPLINGS_TEST(works_for_doubles) {
    CPPLINGS_ASSERT_EQ(max_of(2.5, 1.5), 2.5);
}

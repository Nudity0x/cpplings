// Writing through a pointer changes the pointed-to value.

#include "cpplings_test.hpp"

CPPLINGS_TEST(write_through) {
    int value = 1;
    int* ptr = &value;
    *ptr = 99;
    CPPLINGS_ASSERT_EQ(value, 99);
}

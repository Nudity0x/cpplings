// A pointer holds the address of a value. Dereference with * to read it.

#include "cpplings_test.hpp"

CPPLINGS_TEST(deref) {
    int value = 42;
    int* ptr = &value;
    CPPLINGS_ASSERT_EQ(*ptr, 42);
}

// A pointer holds the address of a value. Dereference with * to read it.
//
// TODO: Make `ptr` point at `value`, then the test reads through it.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

CPPLINGS_TEST(deref) {
    int value = 42;
    int* ptr = nullptr;  // TODO: point this at `value`
    CPPLINGS_ASSERT_EQ(*ptr, 42);
}

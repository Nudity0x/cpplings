// A pointer can be null. Dereferencing a null pointer is undefined behavior,
// so you check before you use it.
//
// TODO: Fix `value_or_zero` so it returns *p when p is non-null, and 0 when p
// is null. Right now it always dereferences, which would crash on nullptr.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

int value_or_zero(const int* p) {
    // TODO: guard against nullptr before dereferencing.
    return *p;
}

CPPLINGS_TEST(handles_null) {
    int x = 42;
    CPPLINGS_ASSERT_EQ(value_or_zero(&x), 42);
    CPPLINGS_ASSERT_EQ(value_or_zero(nullptr), 0);
}

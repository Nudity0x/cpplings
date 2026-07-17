// A pointer can be null. Dereferencing a null pointer is undefined behavior,
// so you check before you use it.

#include "cpplings_test.hpp"

int value_or_zero(const int* p) {
    if (p == nullptr) {
        return 0;
    }
    return *p;
}

CPPLINGS_TEST(handles_null) {
    int x = 42;
    CPPLINGS_ASSERT_EQ(value_or_zero(&x), 42);
    CPPLINGS_ASSERT_EQ(value_or_zero(nullptr), 0);
}

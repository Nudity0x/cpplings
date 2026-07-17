// Writing through a pointer changes the pointed-to value.
//
// TODO: Through `ptr`, set the value it points at to 99 so the test passes.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

CPPLINGS_TEST(write_through) {
    int value = 1;
    int* ptr = &value;
    // TODO: assign 99 through ptr
    CPPLINGS_ASSERT_EQ(value, 99);
}

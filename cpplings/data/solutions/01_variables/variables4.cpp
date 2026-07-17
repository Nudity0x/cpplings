// Integer types have different sizes. `int` is typically 4 bytes.

#include "cpplings_test.hpp"

CPPLINGS_TEST(count_holds_300) {
    int count = 300;
    CPPLINGS_ASSERT_EQ(static_cast<int>(count), 300);
}

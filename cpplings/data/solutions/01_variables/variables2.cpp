// Variables can be initialized when declared.

#include "cpplings_test.hpp"

CPPLINGS_TEST(x_is_ten) {
    int x = 10;
    CPPLINGS_ASSERT_EQ(x, 10);
}

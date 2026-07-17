// Variables must be declared with a type in C++.

#include "cpplings_test.hpp"

int answer = 42;

CPPLINGS_TEST(answer_is_42) {
    CPPLINGS_ASSERT_EQ(answer, 42);
}

// if / else if / else choose a branch based on a condition.

#include "cpplings_test.hpp"
#include <string>

std::string classify(int n) {
    if (n < 0) {
        return "negative";
    } else if (n == 0) {
        return "zero";
    } else {
        return "positive";
    }
}

CPPLINGS_TEST(classify_sign) {
    CPPLINGS_ASSERT_EQ(classify(-4), std::string("negative"));
    CPPLINGS_ASSERT_EQ(classify(0), std::string("zero"));
    CPPLINGS_ASSERT_EQ(classify(7), std::string("positive"));
}

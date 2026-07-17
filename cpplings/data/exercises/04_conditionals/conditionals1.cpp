// if / else if / else choose a branch based on a condition.
//
// TODO: Complete `classify` so it returns "negative", "zero", or "positive"
// for the sign of n. The tests below pin down each case.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <string>

std::string classify(int n) {
    // TODO: return the right word for each sign.
    return "";
}

CPPLINGS_TEST(classify_sign) {
    CPPLINGS_ASSERT_EQ(classify(-4), std::string("negative"));
    CPPLINGS_ASSERT_EQ(classify(0), std::string("zero"));
    CPPLINGS_ASSERT_EQ(classify(7), std::string("positive"));
}

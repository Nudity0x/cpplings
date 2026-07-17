// std::string has useful member functions like .size() and .substr().
//
// TODO: Use .size() to get the length of the word so the test passes.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <string>

CPPLINGS_TEST(length) {
    std::string word = "cpplings";
    int len = 0;  // TODO: set len from word's length
    CPPLINGS_ASSERT_EQ(len, 8);
}

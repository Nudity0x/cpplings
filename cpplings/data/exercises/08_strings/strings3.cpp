// std::string offers many member functions: substr, find, size, and more.
//
// TODO: Fix `first_word` so it returns the part of `sentence` before the first
// space. If there is no space, return the whole string. Use find and substr.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <string>

std::string first_word(const std::string& sentence) {
    // TODO: find the first space and return the substring before it.
    return sentence;
}

CPPLINGS_TEST(extracts_first_word) {
    CPPLINGS_ASSERT_EQ(first_word("hello world"), std::string("hello"));
    CPPLINGS_ASSERT_EQ(first_word("single"), std::string("single"));
}

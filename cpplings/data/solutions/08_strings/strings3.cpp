// std::string offers many member functions: substr, find, size, and more.

#include "cpplings_test.hpp"
#include <string>

std::string first_word(const std::string& sentence) {
    std::size_t space = sentence.find(' ');
    if (space == std::string::npos) {
        return sentence;
    }
    return sentence.substr(0, space);
}

CPPLINGS_TEST(extracts_first_word) {
    CPPLINGS_ASSERT_EQ(first_word("hello world"), std::string("hello"));
    CPPLINGS_ASSERT_EQ(first_word("single"), std::string("single"));
}

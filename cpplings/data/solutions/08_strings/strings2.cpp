// std::string has useful member functions like .size() and .substr().

#include "cpplings_test.hpp"
#include <string>

CPPLINGS_TEST(length) {
    std::string word = "cpplings";
    int len = static_cast<int>(word.size());
    CPPLINGS_ASSERT_EQ(len, 8);
}

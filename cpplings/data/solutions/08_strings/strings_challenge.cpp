#include "cpplings_test.hpp"
#include <string>

int count_words(const std::string& sentence) {
    int words = 0;
    bool in_word = false;
    for (char c : sentence) {
        if (c == ' ') {
            in_word = false;
        } else if (!in_word) {
            in_word = true;
            ++words;
        }
    }
    return words;
}

CPPLINGS_TEST(counts_words) {
    CPPLINGS_ASSERT_EQ(count_words(""), 0);
    CPPLINGS_ASSERT_EQ(count_words("hello"), 1);
    CPPLINGS_ASSERT_EQ(count_words("hello world"), 2);
    CPPLINGS_ASSERT_EQ(count_words("  a  b   c "), 3);
    CPPLINGS_ASSERT_EQ(count_words("   "), 0);
}

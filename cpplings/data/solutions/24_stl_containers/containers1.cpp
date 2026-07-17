#include "cpplings_test.hpp"
#include <map>
#include <string>
#include <vector>

std::map<std::string, int> word_count(const std::vector<std::string>& words) {
    std::map<std::string, int> counts;
    for (const std::string& w : words) {
        counts[w] += 1;
    }
    return counts;
}

CPPLINGS_TEST(counts_words) {
    std::map<std::string, int> counts =
        word_count({"a", "b", "a", "c", "a", "b"});

    CPPLINGS_ASSERT_EQ(counts.at("a"), 3);
    CPPLINGS_ASSERT_EQ(counts.at("b"), 2);
    CPPLINGS_ASSERT_EQ(counts.at("c"), 1);
}

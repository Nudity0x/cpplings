#include "cpplings_test.hpp"
#include <map>
#include <string>
#include <vector>

std::map<std::string, int> tally(const std::vector<std::string>& words) {
    std::map<std::string, int> counts;
    for (const std::string& word : words) {
        counts[word]++;
    }
    return counts;
}

int unique_words(const std::map<std::string, int>& counts) {
    return static_cast<int>(counts.size());
}

std::string most_common(const std::map<std::string, int>& counts) {
    std::string best;
    int best_count = -1;
    for (const std::pair<const std::string, int>& entry : counts) {
        if (entry.second > best_count) {
            best_count = entry.second;
            best = entry.first;
        }
    }
    return best;
}

CPPLINGS_TEST(word_frequency_table) {
    std::vector<std::string> words = {
        "red", "blue", "red", "green", "blue", "red"};

    std::map<std::string, int> counts = tally(words);
    CPPLINGS_ASSERT_EQ(counts.at("red"), 3);
    CPPLINGS_ASSERT_EQ(counts.at("blue"), 2);
    CPPLINGS_ASSERT_EQ(counts.at("green"), 1);

    CPPLINGS_ASSERT_EQ(unique_words(counts), 3);
    CPPLINGS_ASSERT_EQ(most_common(counts), std::string("red"));

    // Tie between "a" and "b" at count 1 -> lexicographically smallest is "a".
    std::map<std::string, int> tie = tally({"b", "a"});
    CPPLINGS_ASSERT_EQ(most_common(tie), std::string("a"));
}

// QUIZ 3 — combining maps, optional, and strings.

#include "cpplings_test.hpp"
#include <map>
#include <optional>
#include <string>

std::optional<int> lookup(const std::map<std::string, int>& table,
                          const std::string& key) {
    auto it = table.find(key);
    if (it != table.end()) {
        return it->second;
    }
    return std::nullopt;
}

CPPLINGS_TEST(optional_lookup) {
    std::map<std::string, int> ages = {
        {"Ada", 36},
        {"Grace", 45},
    };

    std::optional<int> found = lookup(ages, "Ada");
    CPPLINGS_ASSERT(found.has_value());
    CPPLINGS_ASSERT_EQ(*found, 36);

    std::optional<int> missing = lookup(ages, "Nobody");
    CPPLINGS_ASSERT_FALSE(missing.has_value());
}

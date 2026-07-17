#include "cpplings_test.hpp"
#include <string>
#include <utility>
#include <vector>

class Profile {
    std::string name_;
    std::vector<std::string> tags_;
public:
    Profile(std::string name, std::vector<std::string> tags)
        : name_(std::move(name)), tags_(std::move(tags)) {}

    const std::string& name() const { return name_; }
    std::size_t tag_count() const { return tags_.size(); }
};

CPPLINGS_TEST(rule_of_zero_copies_and_moves) {
    Profile original("Ada", {"math", "engines"});

    Profile copy = original;
    CPPLINGS_ASSERT_EQ(copy.name(), std::string("Ada"));
    CPPLINGS_ASSERT_EQ(copy.tag_count(), 2u);

    CPPLINGS_ASSERT_EQ(original.name(), std::string("Ada"));
}

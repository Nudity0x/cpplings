#include "cpplings_test.hpp"
#include <string>
#include <utility>
#include <vector>

class ScopeLog {
public:
    void record(std::string event) { events_.push_back(std::move(event)); }

    std::size_t size() const { return events_.size(); }

    const std::string& at(std::size_t i) const { return events_.at(i); }

private:
    std::vector<std::string> events_;
};

CPPLINGS_TEST(value_semantics_come_for_free) {
    ScopeLog original;
    original.record("open");
    original.record(std::string("read"));
    CPPLINGS_ASSERT_EQ(original.size(), static_cast<std::size_t>(2));

    ScopeLog copy = original;
    copy.record("write");
    CPPLINGS_ASSERT_EQ(copy.size(), static_cast<std::size_t>(3));
    CPPLINGS_ASSERT_EQ(original.size(), static_cast<std::size_t>(2));
    CPPLINGS_ASSERT_EQ(original.at(0), std::string("open"));
    CPPLINGS_ASSERT_EQ(copy.at(2), std::string("write"));

    ScopeLog moved = std::move(copy);
    CPPLINGS_ASSERT_EQ(moved.size(), static_cast<std::size_t>(3));
    CPPLINGS_ASSERT_EQ(moved.at(1), std::string("read"));
}

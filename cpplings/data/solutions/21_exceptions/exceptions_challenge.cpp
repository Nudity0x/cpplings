#include "cpplings_test.hpp"
#include <stdexcept>
#include <string>
#include <vector>

class StackError : public std::runtime_error {
public:
    explicit StackError(const std::string& message)
        : std::runtime_error(message) {}
};

class IntStack {
public:
    explicit IntStack(std::size_t capacity) : capacity_(capacity) {}

    void push(int v) {
        if (items_.size() >= capacity_) {
            throw StackError("full");
        }
        items_.push_back(v);
    }

    int pop() {
        if (items_.empty()) {
            throw StackError("empty");
        }
        int top = items_.back();
        items_.pop_back();
        return top;
    }

    int size() const { return static_cast<int>(items_.size()); }

private:
    std::size_t capacity_;
    std::vector<int> items_;
};

CPPLINGS_TEST(stack_reports_misuse_via_exceptions) {
    IntStack s(2);
    CPPLINGS_ASSERT_EQ(s.size(), 0);

    s.push(10);
    s.push(20);
    CPPLINGS_ASSERT_EQ(s.size(), 2);

    bool full_caught = false;
    try {
        s.push(30);
    } catch (const std::exception&) {
        full_caught = true;
    }
    CPPLINGS_ASSERT(full_caught);

    CPPLINGS_ASSERT_EQ(s.pop(), 20);
    CPPLINGS_ASSERT_EQ(s.pop(), 10);

    bool empty_caught = false;
    try {
        s.pop();
    } catch (const std::exception&) {
        empty_caught = true;
    }
    CPPLINGS_ASSERT(empty_caught);
}

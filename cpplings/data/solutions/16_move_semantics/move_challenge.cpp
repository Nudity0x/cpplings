#include "cpplings_test.hpp"
#include <utility>

class IntStack {
    int* data_;
    int size_;
    int cap_;

public:
    IntStack() : data_(nullptr), size_(0), cap_(0) {}

    IntStack(const IntStack&) = delete;
    IntStack& operator=(const IntStack&) = delete;

    IntStack(IntStack&& other) noexcept
        : data_(other.data_), size_(other.size_), cap_(other.cap_) {
        other.data_ = nullptr;
        other.size_ = 0;
        other.cap_ = 0;
    }

    IntStack& operator=(IntStack&& other) noexcept {
        if (this != &other) {
            delete[] data_;
            data_ = other.data_;
            size_ = other.size_;
            cap_ = other.cap_;
            other.data_ = nullptr;
            other.size_ = 0;
            other.cap_ = 0;
        }
        return *this;
    }

    ~IntStack() { delete[] data_; }

    void push(int value) {
        if (size_ == cap_) {
            int new_cap = cap_ == 0 ? 4 : cap_ * 2;
            int* bigger = new int[new_cap];
            for (int i = 0; i < size_; ++i) {
                bigger[i] = data_[i];
            }
            delete[] data_;
            data_ = bigger;
            cap_ = new_cap;
        }
        data_[size_] = value;
        ++size_;
    }

    int size() const { return size_; }
    int top() const { return data_[size_ - 1]; }
    bool empty() const { return size_ == 0; }
};

CPPLINGS_TEST(move_transfers_stack_ownership) {
    IntStack a;
    a.push(10);
    a.push(20);
    a.push(30);

    IntStack b(std::move(a));
    CPPLINGS_ASSERT_EQ(b.size(), 3);
    CPPLINGS_ASSERT_EQ(b.top(), 30);
    CPPLINGS_ASSERT(a.empty());

    IntStack c;
    c.push(99);
    c = std::move(b);
    CPPLINGS_ASSERT_EQ(c.size(), 3);
    CPPLINGS_ASSERT_EQ(c.top(), 30);
    CPPLINGS_ASSERT(b.empty());
}

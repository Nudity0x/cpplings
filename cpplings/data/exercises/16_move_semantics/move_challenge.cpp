// CHALLENGE — move semantics (Rule of Five, std::move, ownership transfer).
//
// Builds on: classes (14), pointers (09), the Rule of Five from move2.
//
// Challenges are the last, hardest exercise in a section: longer, and they pull
// the section together while reusing earlier topics.
//
// TODO: `IntStack` is a tiny stack that owns a raw heap array. Because it owns a
// resource, it follows the Rule of Five. The copy operations are deleted for you.
// You must finish the MOVE constructor and MOVE assignment so ownership transfers
// correctly and the moved-from stack is left empty (null data, zero size/cap).
//
//   - move constructor: steal other's data/size/cap, null out other.
//   - move assignment: release our own data first, then steal other's, then
//     null out other. Guard against self-assignment.
//
// push() and related members are provided. Get the moves right and the test
// (which moves stacks around) will pass with no leaks or double-frees.
//
// I AM NOT DONE

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

    IntStack(IntStack&& other) noexcept {
        // TODO: steal other's data_, size_, cap_, then null/zero out other.
        (void)other;
    }

    IntStack& operator=(IntStack&& other) noexcept {
        // TODO: self-assignment guard; delete[] data_; steal other's; zero other.
        (void)other;
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

    // Move-construct b from a: b owns the data, a is empty.
    IntStack b(std::move(a));
    CPPLINGS_ASSERT_EQ(b.size(), 3);
    CPPLINGS_ASSERT_EQ(b.top(), 30);
    CPPLINGS_ASSERT(a.empty());

    // Move-assign into c.
    IntStack c;
    c.push(99);
    c = std::move(b);
    CPPLINGS_ASSERT_EQ(c.size(), 3);
    CPPLINGS_ASSERT_EQ(c.top(), 30);
    CPPLINGS_ASSERT(b.empty());
}

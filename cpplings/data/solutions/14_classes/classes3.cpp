// Encapsulation: private data guarded by public methods.

#include "cpplings_test.hpp"

class Counter {
private:
    int count_;

public:
    Counter() : count_(0) {}

    void increment() {
        ++count_;
    }

    int value() const {
        return count_;
    }
};

CPPLINGS_TEST(counts_up) {
    Counter c;
    CPPLINGS_ASSERT_EQ(c.value(), 0);
    c.increment();
    c.increment();
    CPPLINGS_ASSERT_EQ(c.value(), 2);
}

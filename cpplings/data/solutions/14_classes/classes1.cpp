// A class bundles data with the functions that operate on it.

#include "cpplings_test.hpp"

class Counter {
    int count_ = 0;

public:
    void increment() {
        count_++;
    }

    int get() const {
        return count_;
    }
};

CPPLINGS_TEST(counts) {
    Counter c;
    c.increment();
    c.increment();
    CPPLINGS_ASSERT_EQ(c.get(), 2);
}

// A class bundles data with the functions that operate on it. Members are
// private by default; use `public:` to expose an interface.
//
// TODO: The test needs to read the counter's value, but `get()` is private.
// Move it under `public:` so the test compiles.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

class Counter {
    int count_ = 0;

    int get() const {
        return count_;
    }

public:
    void increment() {
        count_++;
    }
};

CPPLINGS_TEST(counts) {
    Counter c;
    c.increment();
    c.increment();
    CPPLINGS_ASSERT_EQ(c.get(), 2);
}

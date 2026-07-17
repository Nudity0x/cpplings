// Encapsulation: private data guarded by public methods. A constructor sets
// up the invariant; getters expose read-only views.
//
// TODO: Give `Counter` a constructor that starts `count_` at 0, an `increment()`
// that adds 1, and a `value() const` getter. The test drives all three.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

class Counter {
private:
    int count_;

public:
    // TODO: constructor initializing count_ to 0.
    // TODO: void increment();
    // TODO: int value() const;
};

CPPLINGS_TEST(counts_up) {
    Counter c;
    CPPLINGS_ASSERT_EQ(c.value(), 0);
    c.increment();
    c.increment();
    CPPLINGS_ASSERT_EQ(c.value(), 2);
}

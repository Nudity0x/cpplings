// IDIOM 2 — RAII (Resource Acquisition Is Initialization).
//
// In C++ you don't release resources by hand at the end of a function — you tie
// the resource's lifetime to an object. The constructor acquires, the destructor
// releases, and the release happens automatically when the object leaves scope,
// even if an exception is thrown. This is the single most important C++ idiom
// (C++ Core Guidelines R.1).
//
// Here a `Guard` bumps a shared counter on construction and must drop it back on
// destruction, so the count always returns to zero no matter how we leave scope.
//
// TODO: Implement the destructor so it decrements *count_. The constructor
// (given) already incremented it. The test checks the counter is balanced.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

class Guard {
    int* count_;
public:
    explicit Guard(int* count) : count_(count) { ++(*count_); }

    // RAII classes own a resource, so they follow the Rule of Five. Copying a
    // Guard would double-release, so we forbid copies.
    Guard(const Guard&) = delete;
    Guard& operator=(const Guard&) = delete;

    ~Guard() {
        // TODO: decrement *count_ to release what the constructor acquired.
    }
};

CPPLINGS_TEST(raii_balances_the_count) {
    int active = 0;

    {
        Guard g(&active);
        CPPLINGS_ASSERT_EQ(active, 1);  // acquired

        {
            Guard nested(&active);
            CPPLINGS_ASSERT_EQ(active, 2);
        }  // nested released here

        CPPLINGS_ASSERT_EQ(active, 1);
    }  // g released here

    CPPLINGS_ASSERT_EQ(active, 0);  // everything cleaned up
}

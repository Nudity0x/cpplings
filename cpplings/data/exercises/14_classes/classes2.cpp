// A constructor initializes an object when it is created.
//
// TODO: Add a constructor that takes an initial balance and stores it, so the
// test that constructs Account{100} passes.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

class Account {
    int balance_ = 0;

public:
    // TODO: add a constructor taking an int initial balance

    int balance() const {
        return balance_;
    }
};

CPPLINGS_TEST(initial_balance) {
    Account a{100};
    CPPLINGS_ASSERT_EQ(a.balance(), 100);
}

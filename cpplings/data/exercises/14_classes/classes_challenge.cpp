// CHALLENGE — classes (encapsulation, constructors, methods, invariants).
//
// Builds on: functions (06), conditionals (04), references (10).
//
// Challenges are the last, hardest exercise in a section: longer, and they pull
// the section together while reusing earlier topics.
//
// TODO: A `BankAccount` class enforces an invariant: the balance can never go
// negative. Implement:
//   - a constructor taking an initial balance (assume it's >= 0)
//   - `deposit(amount)`: add amount if amount > 0
//   - `withdraw(amount)`: subtract amount ONLY if amount > 0 and the balance is
//     large enough; return true if the withdrawal happened, false otherwise
//   - `balance()` const: return the current balance
// The private data must stay non-negative at all times.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

class BankAccount {
    int balance_;
public:
    explicit BankAccount(int initial) : balance_(initial) {}

    void deposit(int amount) {
        // TODO: add amount only if it is positive.
    }

    bool withdraw(int amount) {
        // TODO: withdraw only if amount > 0 and balance_ >= amount.
        // Return whether the withdrawal succeeded.
        return false;
    }

    int balance() const {
        // TODO: return the current balance.
        return 0;
    }
};

CPPLINGS_TEST(account_enforces_invariant) {
    BankAccount acct(100);
    CPPLINGS_ASSERT_EQ(acct.balance(), 100);

    acct.deposit(50);
    CPPLINGS_ASSERT_EQ(acct.balance(), 150);

    acct.deposit(-999);  // ignored
    CPPLINGS_ASSERT_EQ(acct.balance(), 150);

    CPPLINGS_ASSERT(acct.withdraw(70));
    CPPLINGS_ASSERT_EQ(acct.balance(), 80);

    CPPLINGS_ASSERT_FALSE(acct.withdraw(1000));  // too much
    CPPLINGS_ASSERT_EQ(acct.balance(), 80);

    CPPLINGS_ASSERT_FALSE(acct.withdraw(-5));  // invalid
    CPPLINGS_ASSERT_EQ(acct.balance(), 80);
}

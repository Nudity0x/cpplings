#include "cpplings_test.hpp"

class BankAccount {
    int balance_;
public:
    explicit BankAccount(int initial) : balance_(initial) {}

    void deposit(int amount) {
        if (amount > 0) {
            balance_ += amount;
        }
    }

    bool withdraw(int amount) {
        if (amount > 0 && balance_ >= amount) {
            balance_ -= amount;
            return true;
        }
        return false;
    }

    int balance() const {
        return balance_;
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

#include "cpplings_test.hpp"

class Animal {
public:
    virtual int sound() const { return 0; }
    virtual ~Animal() = default;
};

class Cat : public Animal {
public:
    int sound() const override { return 5; }
    int meow() const { return 5; }
};

int describe(const Animal& a) {
    return a.sound();
}

CPPLINGS_TEST(virtual_dispatch) {
    Cat c;
    CPPLINGS_ASSERT_EQ(describe(c), 5);
}

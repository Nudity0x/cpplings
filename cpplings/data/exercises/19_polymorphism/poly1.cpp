// A `virtual` function can be overridden by a derived class. When called
// through a base-class pointer or reference, the *derived* version runs. This
// is runtime polymorphism.
//
// TODO: Mark `Animal::sound` as virtual and have `Cat` override it to return 5
// (the length of "meow"). The test calls sound() through an Animal reference
// and expects the Cat's value.
//
// I AM NOT DONE

#include "cpplings_test.hpp"

class Animal {
public:
    // A polymorphic base class needs a virtual destructor so deleting a derived
    // object through an Animal* runs the right destructor (provided for you).
    virtual ~Animal() = default;

    // TODO: make this virtual.
    int sound() const { return 0; }
};

class Cat : public Animal {
public:
    // TODO: override sound() to return 5.
    int meow() const { return 5; }
};

int describe(const Animal& a) {
    return a.sound();
}

CPPLINGS_TEST(virtual_dispatch) {
    Cat c;
    CPPLINGS_ASSERT_EQ(describe(c), 5);
}

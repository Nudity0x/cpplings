// Inheritance lets a class reuse and extend another. A derived class gets the
// base class's public members. Write `class Derived : public Base { ... }`.
//
// TODO: Make `Dog` inherit publicly from `Animal` so it gets the `legs` member.
// The test constructs a Dog and reads `legs` (which Animal sets to 4).
//
// I AM NOT DONE

#include "cpplings_test.hpp"

class Animal {
public:
    int legs;
    Animal() : legs(4) {}
};

// TODO: make Dog inherit publicly from Animal.
class Dog {
public:
    const char* sound() const { return "woof"; }
};

CPPLINGS_TEST(dog_is_an_animal) {
    Dog d;
    CPPLINGS_ASSERT_EQ(d.legs, 4);
}

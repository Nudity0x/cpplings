#include "cpplings_test.hpp"

class Animal {
public:
    int legs;
    Animal() : legs(4) {}
};

class Dog : public Animal {
public:
    const char* sound() const { return "woof"; }
};

CPPLINGS_TEST(dog_is_an_animal) {
    Dog d;
    CPPLINGS_ASSERT_EQ(d.legs, 4);
}

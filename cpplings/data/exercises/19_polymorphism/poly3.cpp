// When you delete a derived object through a base pointer, the base class needs
// a `virtual` destructor — otherwise the derived destructor won't run and you
// leak resources. Polymorphic base classes should always have one.
//
// TODO: `Base` is missing a virtual destructor, so deleting a Derived through a
// Base* skips Derived's destructor and the counter is never bumped. Add a
// virtual destructor to Base. The test tracks destructor calls.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <memory>

static int derived_destructor_calls = 0;

class Base {
public:
    // TODO: add a virtual destructor.
    virtual int tag() const { return 1; }
};

class Derived : public Base {
public:
    int tag() const override { return 2; }
    ~Derived() { derived_destructor_calls += 1; }
};

CPPLINGS_TEST(virtual_destructor_runs) {
    derived_destructor_calls = 0;
    {
        Base* b = new Derived();
        delete b;  // Must invoke ~Derived through the base pointer.
    }
    CPPLINGS_ASSERT_EQ(derived_destructor_calls, 1);
}

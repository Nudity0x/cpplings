// A factory function can return a unique_ptr, handing ownership to the caller.
// This is the idiomatic C++ way to return heap-allocated objects safely.
//
// TODO: Finish `make_widget` so it returns a unique_ptr<Widget> whose `id` is
// set to the given value. Use std::make_unique. The test takes ownership and
// checks the id.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <memory>

struct Widget {
    int id;
};

std::unique_ptr<Widget> make_widget(int id) {
    // TODO: create a Widget with the given id and return it as a unique_ptr.
    return nullptr;
}

CPPLINGS_TEST(factory_returns_ownership) {
    std::unique_ptr<Widget> w = make_widget(123);
    CPPLINGS_ASSERT(w != nullptr);
    CPPLINGS_ASSERT_EQ(w->id, 123);
}

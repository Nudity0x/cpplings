#include "cpplings_test.hpp"
#include <memory>

struct Widget {
    int id;
};

std::unique_ptr<Widget> make_widget(int id) {
    auto w = std::make_unique<Widget>();
    w->id = id;
    return w;
}

CPPLINGS_TEST(factory_returns_ownership) {
    std::unique_ptr<Widget> w = make_widget(123);
    CPPLINGS_ASSERT(w != nullptr);
    CPPLINGS_ASSERT_EQ(w->id, 123);
}

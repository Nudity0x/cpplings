#include "cpplings_test.hpp"
#include <memory>

CPPLINGS_TEST(unique_ptr_holds_value) {
    std::unique_ptr<int> p = std::make_unique<int>(42);
    CPPLINGS_ASSERT(p != nullptr);
    CPPLINGS_ASSERT_EQ(*p, 42);
}

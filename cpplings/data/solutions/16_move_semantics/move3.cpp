#include "cpplings_test.hpp"
#include <memory>
#include <utility>

std::unique_ptr<int> take_ownership(std::unique_ptr<int>& source) {
    std::unique_ptr<int> taken = std::move(source);
    return taken;
}

CPPLINGS_TEST(move_transfers_and_nulls_source) {
    std::unique_ptr<int> original = std::make_unique<int>(42);

    std::unique_ptr<int> owner = take_ownership(original);

    CPPLINGS_ASSERT(owner != nullptr);
    CPPLINGS_ASSERT_EQ(*owner, 42);
    CPPLINGS_ASSERT(original == nullptr);
}

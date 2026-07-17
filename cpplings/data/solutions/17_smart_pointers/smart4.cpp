#include "cpplings_test.hpp"
#include <memory>
#include <vector>
#include <utility>

CPPLINGS_TEST(move_unique_into_vector) {
    std::unique_ptr<int> owner = std::make_unique<int>(55);
    std::vector<std::unique_ptr<int>> pool;

    pool.push_back(std::move(owner));

    CPPLINGS_ASSERT_EQ(pool.size(), 1u);
    CPPLINGS_ASSERT(owner == nullptr);
    CPPLINGS_ASSERT_EQ(*pool[0], 55);
}

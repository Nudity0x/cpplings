// std::shared_ptr shares ownership: the object lives until the last shared_ptr
// pointing at it is destroyed. use_count() reports how many owners there are.
//
// TODO: Make `second` share ownership of the same object as `first` (copy it,
// don't make a new one). After that, use_count() should be 2 and both must
// observe the same value. Fix the marked line.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <memory>

CPPLINGS_TEST(shared_ownership) {
    std::shared_ptr<int> first = std::make_shared<int>(7);
    // TODO: make `second` a shared owner of the same int as `first`.
    std::shared_ptr<int> second = nullptr;

    CPPLINGS_ASSERT_EQ(first.use_count(), 2);
    CPPLINGS_ASSERT_EQ(*second, 7);

    *second = 99;
    CPPLINGS_ASSERT_EQ(*first, 99);
}

// A unique_ptr cannot be copied — only moved. To store one in a container or
// hand it to another owner, you must std::move it. After the move, the source
// is null.
//
// TODO: Move `owner` into the vector `pool` using std::move, so ownership
// transfers. After the move, `owner` must be null and the vector must hold the
// object with value 55.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <memory>
#include <vector>
#include <utility>

CPPLINGS_TEST(move_unique_into_vector) {
    std::unique_ptr<int> owner = std::make_unique<int>(55);
    std::vector<std::unique_ptr<int>> pool;

    // TODO: transfer ownership of `owner` into `pool`.

    CPPLINGS_ASSERT_EQ(pool.size(), 1u);
    CPPLINGS_ASSERT(owner == nullptr);
    CPPLINGS_ASSERT_EQ(*pool[0], 55);
}

// std::move doesn't move anything by itself — it casts a value to an rvalue so
// that a move constructor or move assignment gets chosen instead of a copy.
//
// std::unique_ptr is the clearest example: it is move-only (it CANNOT be
// copied), and the standard guarantees a moved-from unique_ptr is left equal to
// nullptr. That makes the transfer of ownership observable and well-defined —
// unlike, say, a moved-from std::string, whose contents are only "valid but
// unspecified".
//
// TODO: `take_ownership` should MOVE the given unique_ptr into the returned
// value using std::move, not try to copy it (copying won't compile). After the
// call the caller's pointer must be null. Complete the function.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <memory>
#include <utility>

std::unique_ptr<int> take_ownership(std::unique_ptr<int>& source) {
    // TODO: move `source` into `taken`, then return taken.
    std::unique_ptr<int> taken;
    return taken;
}

CPPLINGS_TEST(move_transfers_and_nulls_source) {
    std::unique_ptr<int> original = std::make_unique<int>(42);

    std::unique_ptr<int> owner = take_ownership(original);

    // The new owner holds the value...
    CPPLINGS_ASSERT(owner != nullptr);
    CPPLINGS_ASSERT_EQ(*owner, 42);
    // ...and the source is guaranteed null after being moved from.
    CPPLINGS_ASSERT(original == nullptr);
}

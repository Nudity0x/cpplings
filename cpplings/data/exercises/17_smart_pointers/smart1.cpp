// std::unique_ptr owns a heap object exclusively and frees it automatically
// when it goes out of scope. No manual `delete` needed.
//
// Create one with std::make_unique<T>(args). Access the pointee with * or ->.
//
// TODO: Create a unique_ptr<int> holding the value 42, using std::make_unique.
// The test dereferences it and checks the value.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <memory>

CPPLINGS_TEST(unique_ptr_holds_value) {
    // TODO: replace nullptr with a make_unique<int> holding 42.
    std::unique_ptr<int> p = nullptr;
    CPPLINGS_ASSERT(p != nullptr);
    CPPLINGS_ASSERT_EQ(*p, 42);
}

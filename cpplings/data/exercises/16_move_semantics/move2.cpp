// A move constructor transfers ownership of a resource from one object to
// another, leaving the source empty. It takes an rvalue reference (Type&&).
//
// This `Buffer` owns a raw heap allocation, so it follows the Rule of Five: a
// class that manages a resource and declares any of {destructor, copy/move
// constructor, copy/move assignment} should handle all five. Here we DELETE the
// copy operations (copying would double-free the buffer) and provide the move
// operations instead. Move constructors should be marked `noexcept` so
// containers like std::vector can move rather than copy them.
//
// TODO: Finish the move constructor so it takes ownership of `other`'s data
// pointer and size, then leaves `other` empty (null pointer, zero size).
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <utility>

class Buffer {
public:
    int* data;
    int size;

    explicit Buffer(int n) : data(new int[n]()), size(n) {}

    // Copying would leave two owners of the same pointer -> double free.
    // Deleting the copy operations makes that a compile error instead of a bug.
    Buffer(const Buffer&) = delete;
    Buffer& operator=(const Buffer&) = delete;

    // Move constructor: steal the resource, leave the source safely empty.
    Buffer(Buffer&& other) noexcept {
        // TODO: take other's data and size, then null out other.
    }

    // Move assignment completes the Rule of Five (provided for you here).
    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    ~Buffer() { delete[] data; }
};

CPPLINGS_TEST(move_transfers_ownership) {
    Buffer a(10);
    int* original = a.data;

    Buffer b(std::move(a));

    CPPLINGS_ASSERT_EQ(b.size, 10);
    CPPLINGS_ASSERT(b.data == original);
    CPPLINGS_ASSERT(a.data == nullptr);
    CPPLINGS_ASSERT_EQ(a.size, 0);
}

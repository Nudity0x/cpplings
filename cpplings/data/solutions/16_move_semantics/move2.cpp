#include "cpplings_test.hpp"
#include <utility>

class Buffer {
public:
    int* data;
    int size;

    explicit Buffer(int n) : data(new int[n]()), size(n) {}

    Buffer(const Buffer&) = delete;
    Buffer& operator=(const Buffer&) = delete;

    Buffer(Buffer&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }

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

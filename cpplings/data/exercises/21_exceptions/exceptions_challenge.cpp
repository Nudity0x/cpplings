// CHALLENGE — exceptions (custom types, throw/catch, RAII cleanup on unwind).
//
// Builds on: classes (14), inheritance (18), references (10).
//
// Challenges are the last, hardest exercise in a section: longer, and they pull
// the section together while reusing earlier topics.
//
// TODO: A tiny bounded stack that reports misuse through exceptions.
//   1. Define `StackError` deriving from std::runtime_error, forwarding a
//      message to its base.
//   2. `IntStack` holds up to `capacity` ints (given at construction).
//      - `push(v)` throws StackError("full") when already at capacity.
//      - `pop()` throws StackError("empty") when there is nothing to pop,
//        otherwise removes and returns the top value.
//      - `size()` returns the current count.
// Make the test below read like ordinary stack use, with errors as exceptions.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <stdexcept>
#include <string>
#include <vector>

// TODO: make StackError derive from std::runtime_error.
class StackError {
};

class IntStack {
public:
    // TODO: construct with a fixed capacity.
    // TODO: void push(int v);   // throw StackError("full") when full
    // TODO: int pop();          // throw StackError("empty") when empty
    // TODO: int size() const;
};

CPPLINGS_TEST(stack_reports_misuse_via_exceptions) {
    IntStack s(2);
    CPPLINGS_ASSERT_EQ(s.size(), 0);

    s.push(10);
    s.push(20);
    CPPLINGS_ASSERT_EQ(s.size(), 2);

    bool full_caught = false;
    try {
        s.push(30);
    } catch (const std::exception&) {
        full_caught = true;
    }
    CPPLINGS_ASSERT(full_caught);

    CPPLINGS_ASSERT_EQ(s.pop(), 20);
    CPPLINGS_ASSERT_EQ(s.pop(), 10);

    bool empty_caught = false;
    try {
        s.pop();
    } catch (const std::exception&) {
        empty_caught = true;
    }
    CPPLINGS_ASSERT(empty_caught);
}

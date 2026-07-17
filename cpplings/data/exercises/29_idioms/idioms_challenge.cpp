// CHALLENGE — idioms (RAII + Rule of Zero + value semantics in one type).
//
// Builds on: the move-by-value sink idiom (idioms3), smart pointers (17), move
// semantics (16), classes (14), vectors (13).
//
// Challenges are the last, hardest exercise in a section: longer, and they pull
// the section together while reusing earlier topics. This is the FINAL
// challenge — it leans on nearly everything before it.
//
// TODO: Build `ScopeLog`, a value type that records a sequence of string
// "events" and can be freely copied AND moved with correct value semantics —
// WITHOUT writing any destructor, copy, or move operations yourself. That is
// the Rule of Zero: hold members that already do the right thing
// (std::vector<std::string>) and let the compiler generate all five special
// members for you (C++ Core Guidelines C.20).
//
//   1. `record(event)` takes the event BY VALUE and moves it into the internal
//      vector (the by-value sink idiom — one overload, optimal for lvalues and
//      rvalues alike).
//   2. `size()` returns how many events were recorded.
//   3. `at(i)` returns a const reference to the i-th event.
//   4. Write NO destructor, NO copy constructor/assignment, NO move
//      constructor/assignment. The defaults must be correct.
//
// The test copies a log, mutates the copy, and confirms the original is
// untouched — proving deep value semantics came for free.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <string>
#include <utility>
#include <vector>

class ScopeLog {
public:
    // TODO: void record(std::string event);   // by-value sink, then move
    // TODO: std::size_t size() const;
    // TODO: const std::string& at(std::size_t i) const;

private:
    // TODO: hold the events in a std::vector<std::string>.
};

CPPLINGS_TEST(value_semantics_come_for_free) {
    ScopeLog original;
    original.record("open");
    original.record(std::string("read"));
    CPPLINGS_ASSERT_EQ(original.size(), static_cast<std::size_t>(2));

    // Copy: the copy is independent (deep) with no code written for it.
    ScopeLog copy = original;
    copy.record("write");
    CPPLINGS_ASSERT_EQ(copy.size(), static_cast<std::size_t>(3));
    CPPLINGS_ASSERT_EQ(original.size(), static_cast<std::size_t>(2));
    CPPLINGS_ASSERT_EQ(original.at(0), std::string("open"));
    CPPLINGS_ASSERT_EQ(copy.at(2), std::string("write"));

    // Move: also free, and leaves a usable (empty-ish) moved-from vector.
    ScopeLog moved = std::move(copy);
    CPPLINGS_ASSERT_EQ(moved.size(), static_cast<std::size_t>(3));
    CPPLINGS_ASSERT_EQ(moved.at(1), std::string("read"));
}

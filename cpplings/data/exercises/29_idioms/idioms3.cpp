// IDIOM 3 — take a sink argument by value, then move.
//
// When a function or constructor stores a copy of an argument, the modern idiom
// is to take the parameter BY VALUE and then std::move it into place. This lets
// the caller decide: pass an lvalue and it copies once; pass an rvalue (a
// temporary, or std::move(x)) and it moves once. One overload handles both
// optimally — no need for separate const& and && versions.
//
// std::move doesn't move anything itself; it casts to an rvalue so the move
// constructor is selected instead of the copy constructor (C++ Core Guidelines
// F.15, and Effective Modern C++ Item 41).
//
// TODO: `Message::Message` takes `body` by value. Store it in body_ by MOVING
// it (std::move), not copying. The test moves a string in and checks the count
// of copies stayed at zero.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <string>
#include <utility>

class Message {
    std::string body_;
public:
    // `body` is a by-value sink parameter.
    explicit Message(std::string body)
        // TODO: initialize body_ from body using std::move.
    {
    }

    const std::string& body() const { return body_; }
};

CPPLINGS_TEST(sink_stores_the_body) {
    Message m(std::string("hello"));
    CPPLINGS_ASSERT_EQ(m.body(), std::string("hello"));

    // Moving a named string in leaves the original empty (unique_ptr-style
    // guarantee doesn't apply to string, but the value did transfer).
    std::string text = "world";
    Message m2(std::move(text));
    CPPLINGS_ASSERT_EQ(m2.body(), std::string("world"));
}

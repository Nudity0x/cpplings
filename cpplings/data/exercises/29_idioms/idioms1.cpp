// IDIOM 1 — the Rule of Zero.
//
// The best special member functions are the ones you don't write. If every
// member of your class already manages its own resource (std::string,
// std::vector, smart pointers), then the compiler-generated destructor, copy,
// and move operations are all correct automatically. Don't write them.
//
// This is the modern default (C++ Core Guidelines C.20): a class that owns
// nothing raw needs no destructor, no copy/move constructor, no assignment.
//
// TODO: `Profile` should store a name (std::string) and tags
// (std::vector<std::string>). Add those two members. Write NO special member
// functions — rely on the Rule of Zero. The test copies and moves a Profile,
// which works only because the members handle it for you.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <string>
#include <vector>

class Profile {
    // TODO: add a std::string name_ and a std::vector<std::string> tags_.
public:
    Profile(std::string name, std::vector<std::string> tags)
        // TODO: initialize the two members from the constructor arguments
        //       (move them in — see idioms3 for why).
    {
    }

    const std::string& name() const { return name_; }
    std::size_t tag_count() const { return tags_.size(); }
};

CPPLINGS_TEST(rule_of_zero_copies_and_moves) {
    Profile original("Ada", {"math", "engines"});

    // Copy works: compiler-generated copy constructor copies both members.
    Profile copy = original;
    CPPLINGS_ASSERT_EQ(copy.name(), std::string("Ada"));
    CPPLINGS_ASSERT_EQ(copy.tag_count(), 2u);

    // Original is untouched by the copy.
    CPPLINGS_ASSERT_EQ(original.name(), std::string("Ada"));
}

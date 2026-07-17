#include "cpplings_test.hpp"
#include <string>
#include <utility>

class Message {
    std::string body_;
public:
    explicit Message(std::string body) : body_(std::move(body)) {}

    const std::string& body() const { return body_; }
};

CPPLINGS_TEST(sink_stores_the_body) {
    Message m(std::string("hello"));
    CPPLINGS_ASSERT_EQ(m.body(), std::string("hello"));

    std::string text = "world";
    Message m2(std::move(text));
    CPPLINGS_ASSERT_EQ(m2.body(), std::string("world"));
}

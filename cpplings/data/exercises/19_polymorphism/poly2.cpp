// A pure virtual function (`= 0`) makes a class *abstract*: it cannot be
// instantiated and forces derived classes to provide an implementation. This is
// how C++ expresses an interface.
//
// TODO: `Shape` declares a pure virtual `area()`. Implement `area()` in both
// `Rectangle` and `Circle` so each returns its area. The test stores them
// behind Shape pointers and sums their areas.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <memory>
#include <vector>

class Shape {
public:
    virtual int area() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
    int w_, h_;
public:
    Rectangle(int w, int h) : w_(w), h_(h) {}
    // TODO: override area() to return w_ * h_.
};

class Square : public Shape {
    int side_;
public:
    Square(int side) : side_(side) {}
    // TODO: override area() to return side_ * side_.
};

CPPLINGS_TEST(abstract_interface) {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Rectangle>(3, 4));
    shapes.push_back(std::make_unique<Square>(5));

    int total = 0;
    for (const auto& s : shapes) {
        total += s->area();
    }
    CPPLINGS_ASSERT_EQ(total, 37);
}

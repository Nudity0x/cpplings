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
    int area() const override { return w_ * h_; }
};

class Square : public Shape {
    int side_;
public:
    explicit Square(int side) : side_(side) {}
    int area() const override { return side_ * side_; }
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

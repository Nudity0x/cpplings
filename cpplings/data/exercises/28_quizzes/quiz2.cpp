// QUIZ 2 — combining inheritance, polymorphism, and smart pointers.
//
// No new concepts. A polymorphic hierarchy of shapes stored behind base-class
// pointers, with virtual dispatch selecting the right area() at runtime.
//
// TODO: Implement `perimeter()` in both Rectangle and Circle so each returns
// its perimeter as an int. Rectangle's perimeter is 2*(w+h). Circle's is
// 2*3*r (we use 3 as a whole-number stand-in for pi to keep results integral).
// The test sums the perimeters through Shape pointers.
//
// I AM NOT DONE

#include "cpplings_test.hpp"
#include <memory>
#include <vector>

class Shape {
public:
    virtual int perimeter() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
    int w_, h_;
public:
    Rectangle(int w, int h) : w_(w), h_(h) {}
    // TODO: override perimeter() to return 2 * (w_ + h_).
};

class Circle : public Shape {
    int r_;
public:
    explicit Circle(int r) : r_(r) {}
    // TODO: override perimeter() to return 2 * 3 * r_.
};

CPPLINGS_TEST(polymorphic_perimeters) {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Rectangle>(2, 3));  // 10
    shapes.push_back(std::make_unique<Circle>(5));        // 30

    int total = 0;
    for (const auto& s : shapes) {
        total += s->perimeter();
    }
    CPPLINGS_ASSERT_EQ(total, 40);
}

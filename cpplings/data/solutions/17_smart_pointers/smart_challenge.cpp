#include "cpplings_test.hpp"
#include <memory>
#include <vector>

struct Widget {
    int id;
    explicit Widget(int i) : id(i) {}
};

class Registry {
    std::vector<std::unique_ptr<Widget>> widgets_;

public:
    Widget* add(int id) {
        widgets_.push_back(std::make_unique<Widget>(id));
        return widgets_.back().get();
    }

    int count() const {
        return static_cast<int>(widgets_.size());
    }

    int total_ids() const {
        int sum = 0;
        for (const auto& w : widgets_) {
            sum += w->id;
        }
        return sum;
    }
};

CPPLINGS_TEST(registry_owns_widgets) {
    Registry reg;
    Widget* a = reg.add(10);
    Widget* b = reg.add(32);

    CPPLINGS_ASSERT(a != nullptr);
    CPPLINGS_ASSERT(b != nullptr);
    CPPLINGS_ASSERT_EQ(a->id, 10);
    CPPLINGS_ASSERT_EQ(b->id, 32);

    CPPLINGS_ASSERT_EQ(reg.count(), 2);
    CPPLINGS_ASSERT_EQ(reg.total_ids(), 42);
}

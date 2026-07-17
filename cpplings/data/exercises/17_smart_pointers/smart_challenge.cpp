// CHALLENGE — smart pointers (unique_ptr, shared_ptr, ownership).
//
// Builds on: classes (14), vectors (13), move semantics (16).
//
// Challenges are the last, hardest exercise in a section: longer, and they pull
// the section together while reusing earlier topics.
//
// TODO: A `Registry` owns a growing collection of Widgets via
// std::vector<std::unique_ptr<Widget>>. Implement:
//   - `add(int id)`: create a Widget with that id (std::make_unique) and store it,
//     returning a raw NON-owning pointer to it (widget.get()). The registry keeps
//     ownership.
//   - `count()`: how many widgets are stored.
//   - `total_ids()`: sum of every stored widget's id.
// This mixes unique_ptr ownership with a vector and a borrowed (raw) observer
// pointer — the idiomatic "owner holds unique_ptr, hands out raw pointers" split.
//
// I AM NOT DONE

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
        // TODO: make_unique a Widget, keep ownership in widgets_, return a raw
        //       observer pointer to it.
        return nullptr;
    }

    int count() const {
        // TODO: return the number of widgets.
        return 0;
    }

    int total_ids() const {
        // TODO: sum the id of every widget.
        return 0;
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

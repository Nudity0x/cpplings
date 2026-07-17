#include "cpplings_test.hpp"
#include <vector>

struct Student {
    const char* name;
    int score;
};

int average_score(const std::vector<Student>& students) {
    if (students.empty()) {
        return 0;
    }
    int total = 0;
    for (const Student& s : students) {
        total += s.score;
    }
    return total / static_cast<int>(students.size());
}

CPPLINGS_TEST(computes_average) {
    std::vector<Student> class_a = {
        {"Ada", 90},
        {"Linus", 80},
        {"Grace", 100},
    };
    CPPLINGS_ASSERT_EQ(average_score(class_a), 90);

    std::vector<Student> empty;
    CPPLINGS_ASSERT_EQ(average_score(empty), 0);
}

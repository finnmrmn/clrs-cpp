#include "code.hpp"

#include <cassert>
#include <iostream>
#include <string>

template <typename T>
void test_sort(std::vector<T> actual, std::vector<T> expected) {
    auto insertion_actual{actual};
    insertion_sort(insertion_actual);
    assert(insertion_actual == expected);
    auto selection_actual{actual};
    selection_sort(selection_actual);
    assert(selection_actual == expected);
}

void test_suite_sort(void) {
    test_sort<int>({1, 2, 3, 4, 5}, {1, 2, 3, 4, 5});
    test_sort<int>({5, 4, 3, 2, 1}, {1, 2, 3, 4, 5});
    test_sort<int>({4, 3, 1, 5, 2}, {1, 2, 3, 4, 5});
    test_sort<int>({}, {});
    test_sort<int>({1}, {1});
    test_sort<int>({2, 1}, {1, 2});
    test_sort<std::string>({"abc", "x", "123"}, {"123", "abc", "x"});
}

int main(void) {
    test_suite_sort();
    return 0;
}
#include "code.hpp"

#include <cassert>
#include <iostream>
#include <string>

template <typename T>
void test_insertion_sort(std::vector<T> actual, std::vector<T> expected) {
    insertion_sort(actual);
    assert(actual == expected);
}

void test_suite_insertion_sort(void) {
    test_insertion_sort<int>({1, 2, 3, 4, 5}, {1, 2, 3, 4, 5});
    test_insertion_sort<int>({}, {});
    test_insertion_sort<int>({1}, {1});
    test_insertion_sort<int>({2, 1}, {1, 2});
    test_insertion_sort<std::string>({"abc", "x", "123"}, {"123", "abc", "x"});
}

int main(void) {
    test_suite_insertion_sort();
    return 0;
}
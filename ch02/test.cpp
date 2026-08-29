#include "code.hpp"

#include <iostream>

int main(void) {
    std::vector<int> test{3, 2, 1};
    for (auto i : test)
        std::cout << i;
    insertion_sort(test);
    for (auto i : test)
        std::cout << i;
}
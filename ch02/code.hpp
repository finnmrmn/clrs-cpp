#pragma once

#include <vector>

template <typename T>
void insertion_sort(std::vector<T>& v) {
    for (size_t i = 1; i < v.size(); i++) {
        T key = v[i];
        size_t j = i;
        while (j > 0 && v[j - 1] > key) {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = key;
    }
}
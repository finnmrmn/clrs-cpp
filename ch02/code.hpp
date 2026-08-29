#pragma once

#include <vector>

/// @brief Sorts a vector in place using insertion sort.
/// @note CLRS uses 1-based indexing, which is problematic for C++ 0-based
/// indexing and size_t being non-negative. This shift means j is now the
/// insertion position rather than the position of what is being compared
/// against key.
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
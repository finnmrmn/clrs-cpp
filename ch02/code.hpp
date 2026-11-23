#pragma once

#include <vector>

/// @brief Sorts a vector in place using insertion sort.
/// @note CLRS uses 1-origin indexing, which is problematic for C++ 0-origin
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

/// @brief Sorts a vector in place using selection sort.
/// @note 'n - 1' underflows for size_t when the size of the array is zero, so
/// 'i < n - 1' becomes 'i + 1 < n' (add 1 to both sides) to prevent the
/// underflow from happening.
template <typename T>
void selection_sort(std::vector<T>& v) {
    for (size_t i = 0; i + 1 < v.size(); i++) {
        size_t key_index = i;
        for (size_t j = i + 1; j < v.size(); j++)
            if (v[j] < v[key_index])
                key_index = j;
        T temp = v[i];
        v[i] = v[key_index];
        v[key_index] = temp;
    }
}
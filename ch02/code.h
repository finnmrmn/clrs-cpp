#pragma once

#include <memory.h>

/// @brief Sorts an array in place using insertion sort.
/// @param start Pointer to the start of the array.
/// @param end Pointer to the end of array (after last element).
/// @param step Size of the element of every individual element in the array.
/// @param key Temporary space for the key used in comparisons.
/// @param compare The caller-provided compare function for sorting. Return true
/// if compared elements are in order.
/// @warning Ensure no pointers are nullptr.
/// @warning Ensure 'start' <= 'end'.
/// @warning Ensure 'step' holds the non-zero size of array element.
/// @warning Ensure memory pointed to by 'key' is size of array element.
void insertion_sort(
    void *start,
    void *end,
    size_t step,
    void *key,
    bool (*compare)(const void *, const void *)
);
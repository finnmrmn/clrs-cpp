#pragma once

#include <memory.h>

/// @brief Sorts an array in place using insertion sort.
/// @param start Pointer to the first element of the array.
/// @param end Pointer to one past the last element in the array.
/// @param step Size of each element in bytes.
/// @param key Scratch memory used for copying and comparing elements.
/// @param compare The caller-provided compare function for sorting. Returns
/// false if the elements need swapping.
/// @warning Ensure all pointers are non-null.
/// @warning Ensure start <= end.
/// @warning Ensure step > 0.
/// @warning Ensure key points to at least step bytes of writable memory.
void insertion_sort(
    void *start,
    void *end,
    size_t step,
    void *key,
    bool (*compare)(const void *, const void *)
);
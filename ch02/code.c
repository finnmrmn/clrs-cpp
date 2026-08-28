#include "code.h"

void insertion_sort(
    void *start,
    void *end,
    size_t step,
    void *key,
    bool (*compare)(const void *, const void *)
) {
    char *s = start;
    char *e = end;
    for (char *i = s + step; i < e; i += step) {
        memcpy(key, i, step);
        char *j = i - step;
        while (j >= s && compare(j, key)) {
            memcpy(j + step, j, step);
            j -= step;
        }
        memcpy(j + step, key, step);
    }
}
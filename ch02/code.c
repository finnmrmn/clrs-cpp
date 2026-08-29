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
        char *j = i;
        while (j > s && !compare(j - step, key)) {
            memcpy(j, j - step, step);
            j -= step;
        }
        memcpy(j, key, step);
    }
}
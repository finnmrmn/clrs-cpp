#include "code.h"

#include <stdlib.h>

bool compare(const void *a, const void *b) {
    return *(const int *)a < *(const int *)b;
}

int main(void) {
    int test[] = {3, 2, 1, 5, 4};
    insertion_sort(
        test,
        test + sizeof(test) / sizeof(*test),
        sizeof(*test),
        &(int){0},
        compare
    );
    return EXIT_SUCCESS;
}
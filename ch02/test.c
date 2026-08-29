#include "code.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

bool ascending_int(const void *a, const void *b) {
    return *(const int *)a < *(const int *)b;
}

bool ascending_double(const void *a, const void *b) {
    return *(const double *)a < *(const double *)b;
}

bool alphabetical(const void *a, const void *b) {
    const char *const *aa = a;
    const char *const *bb = b;
    return strcmp(*aa, *bb) < 0;
}

/// @brief Some manually-written tests to verify insertion sort works correctly.
void test_insertion_sort(void) {
    {
        int test[] = {1, 2, 3, 4, 5};
        int expect[] = {1, 2, 3, 4, 5};
        insertion_sort(
            test,
            test + sizeof(test) / sizeof(*test),
            sizeof(*test),
            &(int){0},
            ascending_int
        );
        assert(!memcmp(test, expect, sizeof(test)));
    }
    {
        int test[] = {3, 2, 1, 5, 4};
        int expect[] = {1, 2, 3, 4, 5};
        insertion_sort(
            test,
            test + sizeof(test) / sizeof(*test),
            sizeof(*test),
            &(int){0},
            ascending_int
        );
        assert(!memcmp(test, expect, sizeof(test)));
    }
    {
        int test[] = {1};
        int expect[] = {1};
        insertion_sort(
            test,
            test + sizeof(test) / sizeof(*test),
            sizeof(*test),
            &(int){0},
            ascending_int
        );
        assert(!memcmp(test, expect, sizeof(test)));
    }
    {
        double test[] = {214.23, 325.5, 21.35, 523.3, 4.2};
        double expect[] = {4.2, 21.35, 214.23, 325.5, 523.3};
        insertion_sort(
            test,
            test + sizeof(test) / sizeof(*test),
            sizeof(*test),
            &(double){0},
            ascending_double
        );
        assert(!memcmp(test, expect, sizeof(test)));
    }
    {
        char *test[] = {"abc", "123", "xyz", "000"};
        char *expect[] = {"000", "123", "abc", "xyz"};
        insertion_sort(
            test,
            test + sizeof(test) / sizeof(*test),
            sizeof(*test),
            &(char *){0},
            alphabetical
        );
        assert(!memcmp(test, expect, sizeof(test)));
    }
}

int main(void) {
    test_insertion_sort();
    return EXIT_SUCCESS;
}
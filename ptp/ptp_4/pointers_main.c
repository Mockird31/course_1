#include "funcs.h"

#ifndef LEN
#error "The length is not entered"
#endif

int main(void)
{
    struct timespec start, stop;
    size_t n = LEN;
    int arr[n];
    add_elems(arr, n);
    int *ps = arr;
    int *pe = arr + n;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    insetrion_sort_pointers(ps, pe);
    clock_gettime(CLOCK_MONOTONIC_RAW, &stop);
    arr[0] = arr[1];
    arr[1] = 1234;
    printf("%llu\n", calc_elapsed_time(&start, &stop));

    return EXIT_SUCCESS;
}
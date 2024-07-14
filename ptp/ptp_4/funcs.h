#ifndef _FUNCS_H_
#define _FUNCS_H_

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void insetrion_sort_ind(int *arr, size_t length);

void insetrion_sort_form_ind(int *arr, size_t length);

void insetrion_sort_pointers(int *ps, int *pe);

void add_elems(int *arr, size_t n);

unsigned long long calc_elapsed_time(const struct timespec *beg, const struct timespec *end);

#endif
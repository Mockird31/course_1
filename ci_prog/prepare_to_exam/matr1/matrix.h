#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "code_errors.h"

#define MAX_LEN 10

typedef int matrix_t[MAX_LEN][MAX_LEN];

int input_matrix(size_t *row, size_t *col, matrix_t matrix);
void swap_rows(int *row1, int *row2, size_t col);
void swap_cols(size_t row, size_t col1, size_t col2, matrix_t matrix);
int find_max_and_min(size_t row, size_t col, matrix_t matrix);
void print_matrix(size_t row, size_t col, matrix_t matrix);

#endif
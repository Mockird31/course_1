#ifndef _MATRIX_H_
#define _MATRIX_H_

#include "code_errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 10

typedef int matrix_t[MAX_SIZE][MAX_SIZE];

int input_matrix(matrix_t mat, size_t *row, size_t *col);
void print_matrix(matrix_t mat, size_t row, size_t col);
int sum_row(int *mat_row, size_t col);
size_t find_max(matrix_t mat, size_t row, size_t col);
int delete_row(matrix_t mat, size_t *row, size_t col);
int delete_col(matrix_t mat, size_t row, size_t *col);

#endif
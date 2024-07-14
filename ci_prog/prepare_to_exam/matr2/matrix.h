#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>
#include <stdlib.h>
#include "code_errors.h"

#define MAX_SIZE 10

typedef int matrix_t[MAX_SIZE][MAX_SIZE];

int input_matrix(size_t *row, size_t *col, matrix_t mat);
int first_triangle(matrix_t mat, size_t row, size_t col);

#endif
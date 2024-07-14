#ifndef _UTILS_H_
#define _UTILS_H

#include "matrix.h"

#define MAX_SIZE 35

int required_bits(unsigned short num);
int check_bit(unsigned short matrix[MAX_ROW][MAX_COL]);
int rewrite_in_arr(unsigned short matrix[MAX_ROW][MAX_COL], size_t row, size_t col, unsigned short array[MAX_SIZE], size_t *len);

#endif
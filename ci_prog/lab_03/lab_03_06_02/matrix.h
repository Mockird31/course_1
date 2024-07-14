#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>
#include <stdbool.h>
#include "codeOut.h"
#define MAX_SIZE 10
#define MAX_SIZE 10

/**
 * @brief Prompts the user to enter the dimensions of a matrix and validates the input.
 *
 * This function asks the user to input the number of rows and columns for a matrix.
 * It checks if the input is valid, i.e., if the number of rows and columns is within the allowed range (1 to MAX_SIZE).
 * If the input is invalid, it prints an error message and returns an error code.
 * If the matrix is a single matrix (1x1), it prints a specific message and returns a special code.
 *
 * @param row Pointer to a size_t variable where the number of rows will be stored.
 * @param col Pointer to a size_t variable where the number of columns will be stored.
 * @return SUCCESS if the input is valid, INPUT_ERROR if the input is invalid, or SINGLE_MATRIX if the matrix is a single matrix.
 */
int enter_matrix(size_t *row, size_t *col);

/**
 * @brief Prints a matrix to the console.
 * 
 * This function iterates through each element of the matrix and prints it to the console.
 * 
 * @param matrix The matrix to be printed.
 * @param row The number of rows in the matrix.
 * @param col The number of columns in the matrix.
 */
void print_matrix(int matrix[MAX_SIZE][MAX_SIZE], size_t row, size_t col);

/**
 * @brief Fills a 2D matrix in a the bull's move pattern starting from the low right corner.
 *
 *
 * @param matrix A 2D array of integers to be filled. The size of the matrix is assumed to be MAX_SIZE x MAX_SIZE.
 * @param row The number of rows in the matrix.
 * @param col The number of columns in the matrix.
 */
void fill_matrix(int matrix[MAX_SIZE][MAX_SIZE], int row, int col);

#endif

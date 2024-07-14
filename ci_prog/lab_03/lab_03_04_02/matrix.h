#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>
#include <math.h>
#include "funcs.h"
#include <stddef.h>
#define MAX_SIZE 10
#define MAX_SIZE 10
#define MAXI -pow(2, 31)
#define DIFF 0.00001

/**
 * @brief Enters a matrix from the user.
 *
 * This function prompts the user to enter the dimensions of a matrix and its elements.
 * It checks for valid input and returns an error code if the input is invalid.
 *
 * @param matrix The matrix to be filled.
 * @param row Pointer to store the number of rows.
 * @param col Pointer to store the number of columns.
 * @return SUCCESS if the matrix is successfully entered, INPUT_ERROR if there's an error in input, or INPUT_ERROR_ELEM if there's an error in element input.
 */
int enter_matrix(int matrix[MAX_SIZE][MAX_SIZE], size_t *row, size_t *col);

/**
 * @brief Finds the maximum element in a given row of a matrix, subject to certain conditions.
 * 
 * This function iterates over a specified row of a matrix to find the maximum element that meets the following criteria:
 * - The element's position in the matrix (i + j) must be greater than the row size minus one.
 * - The element must be greater than the current maximum value found.
 * - The element must pass a check_last function, which is assumed to return 0 if the element is suitable.
 * 
 * If no suitable element is found that meets all conditions, the function prints "No suitable element" and returns a predefined constant NO_ELEMENT.
 * 
 * @param matrix A 2D array representing the matrix to search.
 * @param row The row number to search within the matrix.
 * @return The maximum element found that meets the specified conditions, or NO_ELEMENT if no suitable element is found.
 */
int find_max(int matrix[MAX_SIZE][MAX_SIZE], size_t row);

#endif

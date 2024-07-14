#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>

#define MAX_SIZE 10

/**
 * @brief Reads a matrix from the standard input.
 *
 * This function prompts the user to enter the number of rows and columns for a matrix,
 * then reads the matrix elements from the standard input. It checks for input errors
 * such as invalid row/column sizes or failed element reads.
 *
 * @param a The matrix to be filled with user input.
 * @param row Pointer to a variable that will store the number of rows entered by the user.
 * @param column Pointer to a variable that will store the number of columns entered by the user.
 * @return SUCCESS if the matrix is successfully read, INPUT_ERROR if there is an error in row/column input,
 *         or INPUT_ERROR_ELEMENTS if there is an error reading matrix elements.
 */
int enter_matrix(int a[MAX_SIZE][MAX_SIZE], size_t *row, size_t *column);

/**
 * @brief Determines if each column of a matrix has alternating signs.
 *
 * This function checks each column of the given matrix to see if the elements have alternating signs.
 * It sets the corresponding index in the result array to 1 if the column has alternating signs,
 * and 0 otherwise.
 *
 * @param a The input matrix.
 * @param row The number of rows in the matrix.
 * @param column The number of columns in the matrix.
 * @param result An array to store the results. Each element corresponds to a column in the matrix.
 *               A value of 1 indicates that the column has alternating signs, while 0 indicates otherwise.
 * @return 0 upon completion.
 */
int make_res(int a[MAX_SIZE][MAX_SIZE], size_t row, size_t column, int *arr);

/**
 * Checks if all non-zero elements in a specified column of a 2D array have the same sign.
 *
 * This function iterates through a specified column of a 2D array, checking if all non-zero elements have the same sign.
 * It returns 1 if all non-zero elements in the column have the same sign, 0 otherwise.
 *
 * @param a The 2D array to check.
 * @param row The number of rows in the 2D array.
 * @param col_ind The index of the column to check.
 * @return 1 if all non-zero elements in the specified column have the same sign, 0 otherwise.
 */
int check_column(int a[MAX_SIZE][MAX_SIZE], size_t row, size_t col_штв);

#endif

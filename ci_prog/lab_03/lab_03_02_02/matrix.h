#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>
#include "funcs.h"
#include "codeOut.h"
#define MAX_SIZE_ROW 20
#define MAX_SIZE 10
#define ELEM -1

/**
 * @brief Enters a matrix from the user input.
 * 
 * This function prompts the user to enter the number of rows and columns, followed by the matrix elements.
 * It checks for valid input and returns an error code if the input is invalid.
 * 
 * @param matrix The matrix to be filled.
 * @param row Pointer to the variable holding the number of rows.
 * @param col Pointer to the variable holding the number of columns.
 * @return SUCCESS if the matrix is successfully entered, INPUT_ERROR if there's an error in input, or INPUT_ERROR_ELEM if there's an error in element input.
 */
int enter_matrix(int matrix[MAX_SIZE_ROW][MAX_SIZE], size_t *row, size_t *col);

/**
 * @brief Modifies the matrix by inserting new rows based on certain conditions.
 * 
 * This function iterates through the matrix and inserts a new row with -1 values if the sum of the digits of at least two elements in a row is odd.
 * It updates the row count accordingly.
 * 
 * @param matrix The matrix to be modified.
 * @param row Pointer to the variable holding the number of rows.
 * @param col The number of columns in the matrix.
 * @return SUCCESS if at least one row is inserted, NO_SOLUTIONS if no suitable elements are found, or INPUT_ERROR if there's an error in input.
 */
int make_matrix(int matrix[MAX_SIZE_ROW][MAX_SIZE], size_t *row, size_t col);

/**
 * @brief Inserts a new row into the matrix at a specified index.
 * 
 * This function shifts the rows below the specified index down by one and inserts a new row filled with -1 at the specified index.
 * 
 * @param matrix The matrix to be modified.
 * @param row Pointer to the variable holding the number of rows.
 * @param col The number of columns in the matrix.
 * @param rowind The index at which the new row should be inserted.
 */
void insert_row(int matrix[MAX_SIZE_ROW][MAX_SIZE], size_t *row, size_t col, size_t rowind);

/**
 * @brief Prints the matrix to the standard output.
 * 
 * This function iterates through the matrix and prints each element, formatting the output for readability.
 * 
 * @param matrix The matrix to be printed.
 * @param row The number of rows in the matrix.
 * @param col The number of columns in the matrix.
 */
void print_matrix(int matrix[MAX_SIZE_ROW][MAX_SIZE], size_t row, size_t col);

#endif

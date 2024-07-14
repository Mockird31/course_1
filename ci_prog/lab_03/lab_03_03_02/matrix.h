#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>
#include "codeOut.h"
#define MAX_SIZE 10
#define MAX_SIZE 10

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
 * @brief Calculates the composition of a row in a matrix.
 * 
 * This function calculates the composition (product of all elements) of a given row in the matrix.
 * 
 * @param line The row of the matrix.
 * @param col The number of columns in the matrix.
 * @return The composition of the row.
 */
int row_composition(int line[MAX_SIZE], size_t col);

/**
 * @brief Swaps two rows in a matrix.
 * 
 * This function swaps the two rows in the matrix.
 * 
 * @param matrix The matrix containing the rows to be swapped.
 * @param col The number of columns in the matrix.
 * @param r1 The index of the first row to be swapped.
 * @param r2 The index of the second row to be swapped.
 */
void swap_rows(int *r1, int *r2, size_t col);

/**
 * @brief Sorts the rows of a matrix based on the product of their elements.
 * 
 * This function sorts the rows of a matrix in ascending order based on the product of their elements.
 * It uses a nested loop to compare the products of each pair of rows and swaps them if necessary.
 * 
 * @param matrix The matrix to be sorted.
 * @param row The number of rows in the matrix.
 * @param col The number of columns in the matrix.
 */
void sort_rows(int matrix[MAX_SIZE][MAX_SIZE], size_t row, size_t col);

#endif

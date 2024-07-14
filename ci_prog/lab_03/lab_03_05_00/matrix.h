#ifndef _MATRIX_H_
#define _MATRIX_H_

#include "array.h"
#include "codeOut.h"
#include "funcs.h"
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
 * @brief Prints the elements of a matrix to the standard output.
 *
 * This function iterates through each element of the given matrix and prints it to the standard output.
 * The matrix is formatted such that each row is printed on a new line, and each element within a row is
 * separated by a space. The elements are right-aligned within their column, with a width of 5 characters
 * for each element.
 *
 * @param matrix A 2D array representing the matrix to be printed.
 * @param row The number of rows in the matrix.
 * @param col The number of columns in the matrix.
 *
 * @note The function assumes that the matrix is a square matrix if row and col are equal.
 */
void print_matrix(int matrix[MAX_SIZE][MAX_SIZE], size_t row, size_t col);

/**
 * @brief Appends prime numbers from a given matrix to an array.
 *
 * This function iterates through each element of a 2D matrix, checks if the element is a prime number,
 * and if so, appends it to the provided array. The function updates the length of the array accordingly.
 * If no prime numbers are found, it prints a message indicating that and returns a special value (EMPTY_ARR).
 *
 * @param matrix A 2D array representing the matrix to search for prime numbers.
 * @param row The number of rows in the matrix.
 * @param col The number of columns in the matrix.
 * @param arr A pointer to the array where prime numbers will be appended.
 * @param len A pointer to a size_t variable that will be updated with the new length of the array after appending.
 * @return SUCCESS if at least one prime number is found and appended, EMPTY_ARR if no prime numbers are found.
 */
int append_to_arr(int matrix[MAX_SIZE][MAX_SIZE], size_t row, size_t col, int *arr, size_t *len);

/**
 * @brief Fills a matrix with prime numbers from an array in reverse order.
 *
 * This function iterates over a given matrix and replaces non-prime numbers with elements from an array in reverse order.
 * The array is first reversed to ensure that the elements are filled into the matrix in reverse order.
 *
 * @param[in,out] matrix A 2D array representing the matrix to be filled.
 * @param[in] row The number of rows in the matrix.
 * @param[in] col The number of columns in the matrix.
 * @param[in] arr An array of integers to fill the matrix with. The array is reversed before filling.
 * @param[in] len The length of the array.
 *
 * @note The function assumes that the matrix and array are not null and that the length of the array is sufficient to fill the matrix.
 * @note The function modifies the input matrix in place.
 */
void make_matrix(int matrix[MAX_SIZE][MAX_SIZE], size_t row, size_t col, int *arr, size_t len);

#endif

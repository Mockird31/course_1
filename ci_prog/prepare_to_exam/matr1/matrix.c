#include "matrix.h"

int input_matrix(size_t *row, size_t *col, matrix_t matrix)
{
    if (scanf("%zu", row) != 1 || *row == 0 || *row > MAX_LEN)
    {
        return ERR_INPUT;
    }
    if (scanf("%zu", col) != 1 || *col == 0 || * col > MAX_LEN)
    {
        return ERR_INPUT;
    }
    if (*row == *col)
    {
        return ERR_INPUT;
    }
    for (size_t i = 0; i < *row; i++)
    {
        for (size_t j = 0; j < *col; j++)
        {
            if (scanf("%d", &matrix[i][j]) != 1)
            {
                return ERR_INPUT;
            }
        }
    }
    return EXIT_SUCCESS;
}

void swap_rows(int *row1, int *row2, size_t col)
{
    int temp;
    for (size_t i = 0; i < col; i++)
    {
        temp = row1[i];
        row1[i] = row2[i];
        row2[i] = temp;
    }
}

int find_max_and_min(size_t row, size_t col, matrix_t matrix)
{
    size_t row_min, row_max;
    size_t col_min, col_max;
    int max = INT_MIN;
    int min = INT_MAX;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            if ((matrix[i][j] % 2 == 0) && (matrix[i][j] > max))
            {
                max = matrix[i][j];
                row_max = i;
                col_max = j;
            }
            if ((matrix[i][j] % 2 != 0) && (matrix[i][j] < min))
            {
                min = matrix[i][j];
                row_min = i;
                col_min = j;
            }
        }
    }
    if (max == INT_MIN || min == INT_MAX)
        return ERR_ELEM;
    if (row_max != row_min)
        swap_rows(matrix[row_max], matrix[row_min], col);
    else
        swap_cols(row, col_max, col_min, matrix);
    return EXIT_SUCCESS;
}

void print_matrix(size_t row, size_t col, matrix_t matrix)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            printf("%5d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void swap_cols(size_t row, size_t col1, size_t col2, matrix_t matrix)
{
    int temp;
    for (size_t i = 0; i < row; i++)
    {
        temp = matrix[i][col1];
        matrix[i][col1] = matrix[i][col2];
        matrix[i][col2] = temp;
    }
}
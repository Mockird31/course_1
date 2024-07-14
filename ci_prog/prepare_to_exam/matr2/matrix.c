#include "matrix.h"

int input_matrix(size_t *row, size_t *col, matrix_t mat)
{
    if (scanf("%zu", row) != 1 || *row > MAX_SIZE || *row == 0)
    {
        return INPUT_ERROR;
    }
    if (scanf("%zu", col) != 1 || *col > MAX_SIZE || *col == 0)
    {
        return INPUT_ERROR;
    }
    if (*row != *col)
    {
        return INPUT_ERROR;
    }
    for (size_t i = 0; i < *row; i++)
    {
        for (size_t j = 0; j < *col; j++)
        {
            if (scanf("%d", &mat[i][j]) != 1)
            {
                return INPUT_ERROR;
            }
        }
    }
    return EXIT_SUCCESS;
}

void print_matrix(size_t row, size_t col, matrix_t mat)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            printf("%5d ", mat[i][j]);
        }
        printf("\n");
    }
}

int first_triangle(matrix_t mat, size_t row, size_t col)
{
    int maxi = mat[0][1];
    size_t buf = 1;
    for (size_t i = 0; i < row / 2; i++)
    {
        for (size_t j = 0 + buf; j < col - buf; j++)
        {
            if (mat[i][j] > maxi)
                maxi = mat[i][j];
        }
        buf++;
    }
    return EXIT_SUCCESS;
}
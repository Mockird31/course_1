#include "matrix.h"

int input_matrix(matrix_t mat, size_t *row, size_t *col)
{
    if (scanf("%zu", row) != 1 || *row > MAX_SIZE || *row == 0)
    {
        return INPUT_ERROR;
    }
    if (scanf("%zu", col) != 1 || *col > MAX_SIZE || *col == 0)
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

void print_matrix(matrix_t mat, size_t row, size_t col)
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

int sum_row(int *mat_row, size_t col)
{
    int sum = 0;
    for (size_t i = 0; i < col; i++)
    {
        sum += mat_row[i];
    }
    return sum;
}

size_t find_max(matrix_t mat, size_t row, size_t col)
{
    int max = INT_MIN;
    size_t pos = 0;
    for (size_t i = 0; i < row; i++)
    {
        if (sum_row(mat[i], col) > max)
        {
            max = sum_row(mat[i], col);
            pos = i;
        }
    }
    return pos;
}

int delete_row(matrix_t mat, size_t *row, size_t col)
{
    size_t pos = find_max(mat, *row, col);
    printf("%zu\n", pos);
    if ((pos + 1) == *row)
    {
        (*row)--;
    }
    else
    {
        for (size_t i = pos; i < *row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                mat[i][j] = mat[i + 1][j];
            }
        }
        (*row)--;
    }
    return EXIT_SUCCESS;
}

int delete_col(matrix_t mat, size_t row, size_t *col)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 4; j < *col; j++)
        {
            mat[i][j] = mat[i][j + 1];
        }
    }
    (*col)--;
    return EXIT_SUCCESS;
}

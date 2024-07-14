#include "matrix.h"

int enter_matrix(int matrix[MAX_SIZE][MAX_SIZE], size_t *row, size_t *col)
{
    printf("Enter row: ");
    if (scanf("%zu", row) != 1 || *row == 0 || *row > MAX_SIZE)
    {
        printf("Input error\n");
        return INPUT_ERROR;
    }

    printf("Enter column: ");
    if (scanf("%zu", col) != 1 || *col == 0 || *col > MAX_SIZE)
    {
        printf("Input error\n");
        return INPUT_ERROR;
    }

    if (*row == 1 && *col == 1)
    {
        printf("This is a single matrix\n");
        return SINGLE_MATRIX;
    }

    printf("Enter elements:\n");
    for (size_t i = 0; i < *row; i++)
    {
        for (size_t j = 0; j < *col; j++)
        {
            if (scanf("%d", &matrix[i][j]) != 1)
            {
                printf("Element error\n");
                return INPUT_ERROR_ELEM;
            }
        }
    }
    return SUCCESS;
}

void print_matrix(int matrix[MAX_SIZE][MAX_SIZE], size_t row, size_t col)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
}

int row_composition(int line[MAX_SIZE], size_t col)
{
    int comp = 1;
    for (size_t i = 0; i < col; i++)
    {
        comp *= line[i];
    }
    return comp;
}

void swap_rows(int *r1, int *r2, size_t col)
{
    int temp;
    for (size_t i = 0; i < col; i++)
    {
        temp = r1[i];
        r1[i] = r2[i];
        r2[i] = temp;
    }
}

void sort_rows(int matrix[MAX_SIZE][MAX_SIZE], size_t row, size_t col)
{
    for (size_t i = 0; i < row - 1; i++)
    {
        for (size_t j = i + 1; j < row; j++)
        {
            int product_i = row_composition(matrix[i], col);
            int product_j = row_composition(matrix[j], col);
            if (product_i > product_j)
            {
                swap_rows(matrix[i], matrix[j], col);
            }
        }
    }
}

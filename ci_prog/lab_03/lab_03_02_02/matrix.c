#include "matrix.h"

int enter_matrix(int matrix[MAX_SIZE_ROW][MAX_SIZE], size_t *row, size_t *col)
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

int make_matrix(int matrix[MAX_SIZE_ROW][MAX_SIZE], size_t *row, size_t col)
{
    size_t new_line = 0;
    size_t i = 0;
    while (i < *row)
    {
        size_t counter = 0;
        for (size_t j = 0; j < col; j++)
        {
            if (sum_cif(matrix[i][j]) % 2 != 0)
            {
                counter++;
            }
        }
        if (counter >= 2)
        {
            insert_row(matrix, row, col, i);
            new_line++;
            i += 2;
            (*row)++;
        }
        else
        {
            i++;
        }
    }
    return SUCCESS;
}

void insert_row(int matrix[MAX_SIZE_ROW][MAX_SIZE], size_t *row, size_t col, size_t rowind)
{
    for (size_t i = *row; i > rowind; i--)
    {
        for (size_t j = 0; j < col; j++)
        {
            matrix[i][j] = matrix[i - 1][j];
        }
    }

    for (size_t j = 0; j < col; j++)
    {
        matrix[rowind][j] = ELEM;
    }
}

void print_matrix(int matrix[MAX_SIZE_ROW][MAX_SIZE], size_t row, size_t col)
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

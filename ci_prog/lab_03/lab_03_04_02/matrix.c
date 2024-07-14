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

    if (*row != *col)
    {
        printf("Not a square matrix\n");
        return NOT_SQUARE;
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

int find_max(int matrix[MAX_SIZE][MAX_SIZE], size_t row)
{
    int max = MAXI;
    for (size_t i = 1; i < row; i++)
    {
        for (size_t j = row - i; j < row; j++)
        {
            if (matrix[i][j] > max && check_last(matrix[i][j]) == 0)
            {
                max = matrix[i][j];
            }
        }
    }
    if (max - MAXI < DIFF)
    {
        printf("No suitable element\n");
        return NO_ELEMENT;
    }
    return max;
}

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
            printf("%5d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int append_to_arr(int matrix[MAX_SIZE][MAX_SIZE], size_t row, size_t col, int *arr, size_t *len)
{
    *len = 0;
    size_t counter = 0;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            if (is_prime(matrix[i][j]) == 0)
            {
                counter++;
                append(arr, len, matrix[i][j]);
            }
        }
    }
    if (counter == 0)
    {
        printf("No prime elements\n");
        return EMPTY_ARR;
    }
    return SUCCESS;
}

void make_matrix(int matrix[MAX_SIZE][MAX_SIZE], size_t row, size_t col, int *arr, size_t len)
{
    reverse(arr, len);
    size_t index = 0;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            if (is_prime(matrix[i][j]) == 0)
            {
                matrix[i][j] = arr[index++];
            }
        }
    }
}

#include "matrix.h"
#include "errors.h"

int enter_matrix(int a[MAX_SIZE][MAX_SIZE], size_t *row, size_t *column)
{
    printf("Enter row: ");
    if (scanf("%zu", row) != 1 || *row > MAX_SIZE || *row == 0)
    {
        printf("Input error rows\n");
        return INPUT_ERROR;
    }
    printf("Enter column: ");
    if (scanf("%zu", column) != 1 || *column > MAX_SIZE || *column == 0)
    {
        printf("Input error columns\n");
        return INPUT_ERROR;
    }

    for (size_t i = 0; i < *row; i++)
    {
        for (size_t j = 0; j < *column; j++)
        {
            if (scanf("%d", &a[i][j]) != 1)
            {
                printf("Input error element\n");
                return INPUT_ERROR_ELEMENTS;
            }
        }
    }
    return SUCCESS;
}

int make_res(int a[MAX_SIZE][MAX_SIZE], size_t row, size_t column, int *result)
{
    if (row == 1)
    {
        for (size_t i = 0; i < column; i++)
        {
            result[i] = 0;
        }
        return SUCCESS;
    }
    for (size_t i = 0; i < column; i++)
    {
        result[i] = check_column(a, row, i);
    }
    return SUCCESS;
}

int check_column(int a[MAX_SIZE][MAX_SIZE], size_t row, size_t col_ind)
{
    int res = 0;
    int prev = 0;
    if (a[0][col_ind] != 0)
    {
        prev = a[0][col_ind] > 0 ? 1 : -1;
    }
    else
    {
        return res;
    }
    res = 1;
    for (size_t j = 1; j < row; j++)
    {
        if (a[j][col_ind] == 0)
        {
            res = 0;
            break;
        }
        int current = a[j][col_ind] > 0 ? 1 : -1;
        if (current == prev)
        {
            res = 0;
            break;
        }
        prev = current;
    }
    return res;
}

#include "matrix.h"

int enter_matrix(size_t *row, size_t *col)
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

void fill_matrix(int matrix[MAX_SIZE][MAX_SIZE], int row, int col)
{
    int value = 1;
    int j = col - 1;
    bool state = true;
    while (j >= 0)
    {
        for (int i = row - 1; i >= 0; i--)
        {
            matrix[i][j] = value++;
            state = false;
        }
        j--;
        if (state == false && j >= 0)
        {
            for (int i = 0; i < row; i++)
            {
                matrix[i][j] = value++;
                state = true;
            }
            j--;
        }
    }
}

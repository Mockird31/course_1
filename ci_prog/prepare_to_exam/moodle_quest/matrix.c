#include "matrix.h"

int input_matrix(unsigned short matrix[MAX_ROW][MAX_COL], size_t *row, size_t *col)
{
    int res = scanf("%zu%zu", row, col);
    if (res != 2)
    {
        printf("Input error\n");
        return 2;
    }
    if (*row > 5 || *col > 7)
    {
        printf("Range error\n");
        return 2;
    }
    for (size_t i = 0; i < *row; i++)
    {
        for (size_t j = 0; j < *col; j++)
        {
            res = scanf("%hu", &matrix[i][j]);
            if (res != 1)
            {
                printf("Input error");
                return 2;
            }
        }
    }
    return EXIT_SUCCESS;
}
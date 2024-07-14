#include "utils.h"

int required_bits(unsigned short num)
{
    unsigned short mask1 = 8;
    unsigned short mask2 = 16;
    return ((num & mask1) != 0) || ((num & mask2) != 0);
}

int rewrite_in_arr(unsigned short matrix[MAX_ROW][MAX_COL], size_t row, size_t col, unsigned short array[MAX_SIZE], size_t *len)
{
    *len = 0;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            if (required_bits(matrix[i][j]) == 1)
            {
                array[(*len)++] = matrix[i][j];
            }
        }
    }
    if ((*len) == 0)
    {
        printf("Empty array\n");
        return 2;
    }
    return 0;
}
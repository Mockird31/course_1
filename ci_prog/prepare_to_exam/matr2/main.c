#include "matrix.h"

int main(void)
{
    matrix_t mat;
    size_t row, col;
    int res = input_matrix(&row, &col, mat);
    if (res != EXIT_SUCCESS)
    {
        return res;
    }
    // size_t buf = 1;
    for (size_t j = col; j > (col/2); j--)
    {
        for (size_t i = row - j + 1; i < j; i++)
        { 
            printf("%d ", mat[i][j]);
        }
    }
    return EXIT_SUCCESS;
}
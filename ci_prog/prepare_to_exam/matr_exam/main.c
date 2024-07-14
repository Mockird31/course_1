#include "matrix.h"

int main(void)
{
    matrix_t mat;
    size_t row, col;
    int res = input_matrix(mat, &row, &col);
    if (res != EXIT_SUCCESS)
    {
        return res;
    }
    return EXIT_SUCCESS;
}
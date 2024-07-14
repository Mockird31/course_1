#include "matrix.h"

int main(void)
{
    matrix_t matrix;
    size_t row, col;
    int res = input_matrix(&row, &col, matrix);
    if (res != EXIT_SUCCESS)
    {
        return res;
    }
    res = find_max_and_min(row, col, matrix);
    if (res != EXIT_SUCCESS)
    {
        return res;
    }
    print_matrix(row, col, matrix);
    return EXIT_SUCCESS;
}
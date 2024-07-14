#include "matrix.h"
#include "utils.h"

int main(void)
{
    size_t row, col;
    unsigned short matrix[MAX_ROW][MAX_COL];
    unsigned short array[MAX_SIZE];
    size_t len = 0;
    int res = input_matrix(matrix, &row, &col);
    if (res != 0)
    {
        return EXIT_FAILURE;
    }
    res = rewrite_in_arr(matrix, row, col, array, &len);
    if (res != 0)
    {
        return 2;
    }
    for (size_t i = 0; i < len; i++)
    {
        printf("%hu ", array[i]);
    }
    printf("\n");
    return EXIT_SUCCESS;
}
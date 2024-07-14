/**
 * @file main.c
 * @author Inyakin Roman (inyakinro@student.bmstu.ru)
 * @brief Search for columns where elements alternate
 * @date 2024-04-08
 */
#include "matrix.h"
#include "errors.h"
#include "array.h"

int main(void)
{
    int a[MAX_SIZE][MAX_SIZE];
    size_t row;
    size_t column;
    int res_arr[MAX_SIZE];
    int res = enter_matrix(a, &row, &column);
    if (res != 0)
    {
        return res;
    }
    make_res(a, row, column, res_arr);
    printf("Result:\n");
    print_arr(res_arr, column);
    printf("\n");
    return SUCCESS;
}

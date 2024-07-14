/**
 * @file main.c
 * @author Inyakin Roman (inyakinro@student.bmstu.ru)
 * @brief Sort the rows in ascending order of the product of their elements
 * @date 2024-04-08
 */

#include "matrix.h"

int main(void)
{
    int a[MAX_SIZE][MAX_SIZE];
    size_t row;
    size_t col;
    int res_ent;
    int res_append;
    int arr[MAX_SIZE * MAX_SIZE];
    size_t len;
    res_ent = enter_matrix(a, &row, &col);
    if (res_ent != SUCCESS)
    {
        return res_ent;
    }
    res_append = append_to_arr(a, row, col, arr, &len);
    if (res_append != SUCCESS)
    {
        return res_append;
    }
    make_matrix(a, row, col, arr, len);
    print_matrix(a, row, col);
    return 0;
}

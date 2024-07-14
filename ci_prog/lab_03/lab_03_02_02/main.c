/**
 * @file main.c
 * @author Inyakin Roman (inyakinro@student.bmstu.ru)
 * @brief Insert a row of -1 in front of each row where there are at least two elements whose sum of digits is odd
 * @date 2024-04-08
 */
#include "matrix.h"

int main(void)
{
    int a[MAX_SIZE_ROW][MAX_SIZE];
    size_t row;
    size_t col;
    int res_ent, res_make;
    res_ent = enter_matrix(a, &row, &col);
    if (res_ent != 0)
    {
        return res_ent;
    }
    res_make = make_matrix(a, &row, col);
    if (res_make != 0)
    {
        return res_make;
    }
    print_matrix(a, row, col);
    return 0;
}

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
    res_ent = enter_matrix(&row, &col);
    if (res_ent != 0)
    {
        return res_ent;
    }
    fill_matrix(a, row, col);
    print_matrix(a, row, col);
    return 0;
}

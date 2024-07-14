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
    int res_find;
    res_ent = enter_matrix(a, &row, &col);
    if (res_ent != 0)
    {
        return res_ent;
    }
    res_find = find_max(a, row);
    if (res_find == NO_ELEMENT)
    {
        return res_find;
    }
    printf("%d \n", res_find);
    return 0;
}

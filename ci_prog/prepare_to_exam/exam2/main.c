#include "product.h"

int main(void)
{
    ptrdiff_t len;
    int average;
    product_t products[MAX_PRODUCTS];
    int res = input_prods(&len, products);
    if (res != EXIT_SUCCESS)
    {
        return res;
    }
    average = count_average(products, len);
    find_closest(products, len, average);
    return EXIT_SUCCESS;
}
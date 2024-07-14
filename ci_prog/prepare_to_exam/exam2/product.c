#include "product.h"

int input_prods(ptrdiff_t *len, product_t products[])
{
    if (scanf("%ld", len) != 1)
    {
        return INPUT_ERROR;
    }
    if (*len <= 0)
    {
        return INPUT_ERROR;
    }
    for (ptrdiff_t i = 0; i < *len; i++)
    {
        if (input_one_prod(&products[i]) != EXIT_SUCCESS)
        {
            return INPUT_ERROR;
        }
    }
    return EXIT_SUCCESS;
}

int input_one_prod(product_t *prod)
{
    char temp_str[MAX_LEN + 1];
    int res = input_string(temp_str);
    if (res != EXIT_SUCCESS)
    {
        return res;
    }
    strncpy(prod->name, temp_str, MAX_LEN + 1);
    if (scanf("%d", &prod->price) != 1)
    {
        return INPUT_ERROR;
    }
    if (prod->price < 0)
    {
        return INPUT_ERROR;
    }
    return EXIT_SUCCESS;
}

void print_prod(product_t prod)
{
    printf("%s\n%d\n", prod.name, prod.price);
}

int count_average(product_t products[], ptrdiff_t len)
{
    int average = 0;
    for (ptrdiff_t i = 0; i < len; i++)
    {
        average += products[i].price;
    }
    average /= len;
    return average;
}

void find_closest(product_t products[], ptrdiff_t len, int average)
{
    int difference = INT16_MAX;
    int pos = 0;
    for (ptrdiff_t i = 0; i < len; i++)
    {
        if (abs(products[i].price - average) < difference)
        {
            difference = abs(products[i].price - average);
            pos = i;
        }
    }
    print_prod(products[pos]);
}

int input_string(char *str)
{
    fseek(stdin, 0, SEEK_END);
    char temp[MAX_LEN + 2] = "";
    if (fgets(temp, MAX_LEN + 2, stdin) == NULL)
    {
        return INPUT_ERROR;
    }
    temp[strcspn(temp, "\n")] = '\0';
    if ((strlen(temp) && strlen(temp) > MAX_LEN) || strlen(temp) == 0)
    {
        return INPUT_ERROR;
    }
    strncpy(str, temp, MAX_LEN + 1);
    return EXIT_SUCCESS;
}
#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <limits.h>
#include "error_code.h"

#define MAX_LEN 32
#define MAX_PRODUCTS 100

typedef struct
{
    char name[MAX_LEN + 1];
    int price;
}product_t;

int input_prods(ptrdiff_t *len, product_t products[]);
int input_one_prod(product_t *prod);
int input_string(char *str);
void print_prod(product_t prod);
int count_average(product_t products[], ptrdiff_t len);
void find_closest(product_t products[], ptrdiff_t len, int average);

#endif
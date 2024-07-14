#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <stdint.h>

#define MAX_NAME 30
#define MAX_MAKER 15
#define NUM_OF_FIELDS 4


// Структура для представления продукта
typedef struct
{
    // название продукта
    char name[MAX_NAME + 1];
    // название изготовителя
    char maker[MAX_MAKER + 1];
    // цена товара
    uint32_t price;
    // количество товара
    uint32_t quantity;
} product_t;

#endif

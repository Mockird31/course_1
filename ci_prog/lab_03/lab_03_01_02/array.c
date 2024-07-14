#include "array.h"

void print_arr(int *arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

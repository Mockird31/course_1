#include "array.h"

void append(int *arr, size_t *len, int el)
{
    arr[*len] = el;
    (*len)++;
}

void reverse(int *arr, size_t len)
{
    size_t start = 0;
    size_t end = len - 1;
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

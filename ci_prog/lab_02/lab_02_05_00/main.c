/**
 * @file main.c
 * @author Inyakin Roman (inyakinro@student.bmstu.ru)
 * @brief Finds the maximum amount
 * @date 2024-03-10
 */
#include <stdio.h>
#define SIZE 10

/**
 * @brief Input array
 *
 * @param[in] pa Int a pointer at the first element
 * @param[in] pe Int a pointer to the element after the last one
 * @param[in] length Size_t a length of array
 * @return 0 - If no errors
 * @return 1 - If errors appeared
 */
int enter_arr(int *pa, int *pe);

/**
 * @brief Finds the maximum amount
 *
 * @param[in] pa Int a pointer at the first element
 * @param[in] pe Int a pointer to the element after the last one
 * @return int The maximum amount
 */
int find_max(int *pa, int *pe);

int main(void)
{
    size_t length;
    printf("Enter a length of array: ");
    if (scanf("%zu", &length) != 1 || length == 0 || length > SIZE)
    {
        printf("Input error\n");
        return 1;
    }
    if (length < 2)
    {
        printf("No pair\n");
        return 1;
    }
    int arr[SIZE];
    int *pa = arr;
    int *pe = arr + length;
    if (enter_arr(pa, pe) == 1)
    {
        return 1;
    }
    printf("%d\n", find_max(pa, pe));
    return 0;
}

int enter_arr(int *pa, int *pe)
{
    for (int *pcur = pa; pcur < pe; pcur++)
    {
        printf("Enter an element: ");
        if ((scanf("%d", pcur)) != 1)
        {
            printf("Input error\n");
            return 1;
        }
    }
    return 0;
}

int find_max(int *pa, int *pe)
{
    int max = 0;
    while (pa < pe)
    {
        if ((*pa + *(pe - 1)) > max)
        {
            max = (*pa + *(pe - 1));
        }
        pa++;
        pe--;
    }
    return max;
}

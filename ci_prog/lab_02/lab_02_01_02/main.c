/**
 * @file main.c
 * @author Inyakin Roman (inyakinro@student.bmstu.ru)
 * @brief Search for the arithmetic mean of negative array elements
 * @date 2024-03-10
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define POGRESH 0.000001

/**
 * @brief Entering array elements
 *
 * @param[in] arr Integer array
 * @param[in] n Size_t numbers of elements
 * @return 0 - If no errors
 * @return 1 - If errors appeared
 */
int enter_arr(int *arr, size_t *n);

/**
 * @brief Find the average of all negative elements
 *
 * @param[in] arr
 * @param[in] n Size_t number of elements
 * @param[in] count Int the number of negative elements
 * @return sum/count Double average
 */
double count_arith(int *arr, size_t n);

int main(void)
{
    size_t n;
    double sr_ar;
    int arr[SIZE];

    if (enter_arr(arr, &n) == 1)
    {
        return 1;
    }
    sr_ar = count_arith(arr, n);
    if (sr_ar >= 0)
    {
        printf("No negative elements\n");
        return 1;
    }
    if ((int)sr_ar - sr_ar < POGRESH)
    {
        printf("Srednee arifmeticheskoe otrycatelnykh: %d\n", (int)sr_ar);
    }
    else
    {
        printf("Srednee arifmeticheskoe otrycatelnykh: %lf\n", sr_ar);
    }
    return 0;
}

int enter_arr(int *arr, size_t *n)
{
    printf("Enter a number of elements: ");
    if (scanf("%zu", n) != 1 || *n == 0 || *n > SIZE)
    {
        printf("Input error\n");
        return 1;
    }
    for (size_t i = 0; i < *n; i++)
    {
        printf("Enter a new element: ");
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Input error\n");
            return 1;
        }
    }
    return 0;
}

double count_arith(int *arr, size_t n)
{
    double sum = 0;
    int count = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            sum += arr[i];
            count++;
        }
    }
    if (count == 0)
    {
        return 1;
    }
    return sum / count;
}

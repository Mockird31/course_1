/**
 * @file main.c
 * @author Inyakin Roman (inyakinro@student.bmstu.ru) 
 * @brief A new array, which first contains elements that begin and end with the same digit
 * @date 2024-03-10
 */
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define DEL 10

/**
 * @brief Entering array elements
 *
 * @param[in] arr Integer array
 * @param[in] n Size_t length of array
 * @return 0 - If no errors
 * @return 1 - If errors appeared
 */
int enter_arr(int *arr, size_t *n);

/**
 * @brief Creates a new array into which all elements starting with the same digit are copied
 *
 * @param[in] quantity Int the number of elements satisfying the task
 * @param[in] n Size_t length of array
 * @param[in] arr Integer array the source array
 * @param[in] new_arr Integer array the resulting array
 */
void create_new_arr(int *arr, int *new_arr, size_t n, size_t *quantity);

/**
 * @brief Finds the digit that the element starts with
 *
 * @param[in] num Int The number to find the first digit of
 * @return first_cif Int
 */
int find_first(int num);

/**
 * @brief Print array
 *
 * @param[in] n Size_t length of array
 * @param[in] arr
 */
void print_arr(int *arr, size_t *quantity);

int main(void)
{
    size_t quantity;
    int arr[SIZE];
    size_t n;
    int new_arr[SIZE];
    if (enter_arr(arr, &n) == 1)
    {
        return 1;
    }
    create_new_arr(arr, new_arr, n, &quantity);
    if (quantity == 0)
    {
        printf("No elements\n");
        return 1;
    }
    print_arr(new_arr, &quantity);
    return 0;
}

int enter_arr(int *arr, size_t *n)
{
    *n = 0;
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

void create_new_arr(int *arr, int *new_arr, size_t n, size_t *quantity)
{
    int counter = 0;
    *quantity = 0;
    for (size_t i = 0; i < n; i++)
    {
        int last_cif = abs(arr[i]) % DEL;
        int first_cif = find_first(abs(arr[i]));
        if (last_cif == first_cif)
        {
            new_arr[counter] = arr[i];
            counter++;
            (*quantity)++;
        }
    }
}

int find_first(int num)
{
    int first_cif = 0;
    if (num % DEL == num)
    {
        return num;
    }
    while (num >= DEL)
    {
        first_cif = num / DEL;
        num /= DEL;
    }
    return first_cif;
}

void print_arr(int *arr, size_t *quantity)
{
    for (size_t i = 0; i < *quantity; i++)
    {
        printf("%d\n", arr[i]);
    }
}

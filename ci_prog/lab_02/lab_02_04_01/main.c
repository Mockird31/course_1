/**
 * @file main.c
 * @author Inyakin Roman (inyakinro@student.bmstu.ru)
 * @brief Insertion sort
 * @date 2024-03-10
 */
#include <stdio.h>

#define SIZE 10
#define CODE_FULL_ARRAY 100

/**
 * @brief Entering array elements by the end feature
 *
 * @param[in] arr Integer array
 * @param[in] length Size_t the length of array
 * @return 0 - If no errors
 * @return 100 - If all 10 elements are entered
 * @return 1 - If errors appeared
 */
int enter_arr(int *arr, size_t *length);

/**
 * @brief Print array
 *
 * @param[in] arr Int
 */
void print_arr(int *arr, size_t *length);

/**
 * @brief Insetrion sort
 *
 * @param[in] arr Int the input array
 * @param[in] length Size_t the length of array
 */
void insetrion_sort(int *arr, size_t *length);

int main(void)
{
    int arr[SIZE];
    size_t length = 0;
    int res = enter_arr(arr, &length);
    if (res == 1)
    {
        return res;
    }
    insetrion_sort(arr, &length);
    print_arr(arr, &length);
    return res;
}

int enter_arr(int *arr, size_t *length)
{
    *length = 0;
    printf("Enter an element: ");
    while (scanf("%d", &arr[*length]) == 1)
    {
        printf("Enter an element: ");
        if (*length == SIZE)
        {
            return CODE_FULL_ARRAY;
        }
        ++(*length);
    }

    if (*length == 0)
    {
        printf("Input error\n");
        return 1;
    }
    return 0;
}

void print_arr(int *arr, size_t *length)
{
    for (size_t i = 0; i < *length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insetrion_sort(int *arr, size_t *length)
{
    int newel;
    int location;

    for (size_t i = 1; i < *length; i++)
    {
        newel = arr[i];
        location = i - 1;
        while (location >= 0 && arr[location] > newel)
        {
            arr[location + 1] = arr[location];
            location = location - 1;
        }
        arr[location + 1] = newel;
    }
}

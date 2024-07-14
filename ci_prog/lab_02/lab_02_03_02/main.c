/**
 * @file main.c
 * @author Inyakin Roman (inyakinro@student.bmstu.ru)
 * @brief Delete full squares
 * @date 2024-03-10
 */
#include <stdio.h>
#include <math.h>

#define SIZE 10

/**
 * @brief Entering array elements
 *
 * @param[in] arr Integer array
 * @param[in] n Size_t number of elements
 * @return 0 - If no errors
 * @return 1 - If errors appeared
 */
int enter_arr(int *arr, size_t *n);

/**
 * @brief Print array
 *
 * @param[in] arr Integer array
 * @param[in] n Size_t number of elements
 */
void print_arr(int *arr, size_t *n);

/**
 * @brief Removes full squares
 *
 * @param[in] arr int The input array
 * @param[in] n int The length of array
 */
void delete_full(int *arr, size_t *n, int *counter);

/**
 * @brief Сheck if the number is a complete square
 *
 * @param[in] n int checkable number
 * @return 1 If number if full square
 */
int is_full_square(int n);

int main(void)
{
    size_t n;
    int arr[SIZE];
    int counter;
    if (enter_arr(arr, &n) == 1)
    {
        return 1;
    }
    delete_full(arr, &n, &counter);
    if (counter == 0)
    {
        printf("No full squares\n");
        return 1;
    }
    print_arr(arr, &n);
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

void print_arr(int *arr, size_t *n)
{
    for (size_t i = 0; i < *n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void delete_full(int *arr, size_t *n, int *counter)
{
    int new_el = 0;
    *counter = 0;
    for (size_t i = 0; i < *n; i++)
    {
        if (!is_full_square(arr[i]))
        {
            arr[new_el++] = arr[i];
            (*counter)++;
        }
    }
    *n = new_el;
}

int is_full_square(int n)
{
    int root = (int)sqrt(n);
    return root * root == n;
}

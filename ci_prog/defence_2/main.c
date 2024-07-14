#include <stdio.h>

#define SIZE 10
#define MIN 10e7

int enter_arr(int *arr, size_t *n);
int find_maximum(int *arr, size_t n);
int find_minimum(int *arr, size_t n);
void delete_max_min(int *arr, size_t *n, int maxi, int mini);
void print_arr(int *arr, size_t n);

int main(void)
{
    int arr[SIZE];
    size_t n;
    int maxi;
    int mini;
    if (enter_arr(arr, &n) == 1)
    {
        return 1;
    }
    maxi = find_maximum(arr, n);
    mini = find_minimum(arr, n);
    delete_max_min(arr, &n, maxi, mini);
    if (n == 0)
    {
        printf("Array is empty\n");
        return 1;
    }
    print_arr(arr, n);
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

int find_maximum(int *arr, size_t n)
{
    int maxi = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }
    return maxi;
}

int find_minimum(int *arr, size_t n)
{
    int mini = MIN;
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] < mini)
        {
            mini = arr[i];
        }
    }
    return mini;
}

void delete_max_min(int *arr, size_t *n, int maxi, int mini)
{
    int new_el = 0;

    for (size_t i = 0; i < *n; i++)
    {
        if (!(arr[i] == maxi || arr[i] == mini))
        {
            arr[new_el++] = arr[i];
        }
    }
    *n = new_el;
}

void print_arr(int *arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

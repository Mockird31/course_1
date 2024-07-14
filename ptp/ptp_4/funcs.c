#include "funcs.h"

void insetrion_sort_ind(int *arr, size_t length)
{
    int newel;
    int location;

    for (size_t i = 1; i < length; i++)
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

void insetrion_sort_form_ind(int *arr, size_t length)
{
    int newel;
    int location;

    for (size_t i = 1; i < length; i++)
    {
        newel = *(arr + i);
        location = i - 1;
        while (location >= 0 && *(arr + location) > newel)
        {
            *(arr + location + 1) = *(arr + location);
            location = location - 1;
        }
        *(arr + location + 1) = newel;
    }
}

void insetrion_sort_pointers(int *ps, int *pe)
{
    int newel;
    int *location;

    for (int *pcur = ps + 1; pcur < pe; pcur++)
    {
        newel = *pcur;
        location = pcur;
        while (location > ps && *(location - 1) > newel)
        {
            *location = *(location - 1);
            location--;
        }
        *location = newel;
    }
}

void add_elems(int *arr, size_t n)
{
    srand(time(NULL));
    for (size_t i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
}

unsigned long long calc_elapsed_time(const struct timespec *beg, const struct timespec *end)
{
    return ((unsigned long long)
        (end->tv_sec - beg->tv_sec) * 1000 * 1000 * 1000 +
                        (end->tv_nsec - beg->tv_nsec)) / 1000; 
}


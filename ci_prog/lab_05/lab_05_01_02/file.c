#include "file.h"

int process(FILE *f, size_t *max_index)
{
    int max_num = INT_MIN;
    *max_index = 1;
    size_t index = 1;
    int num1, num2;
    if (fscanf(f, "%d", &num1) != EXIT_FAILURE)
    {
        return NOT_ENOUGH_ELEMS;
    }
    if (fscanf(f, "%d", &num2) != EXIT_FAILURE)
    {
        *max_index = 1;
        return EXIT_SUCCESS;
    }
    do
    {
        index += 1;
        if (num2 > num1 && num2 > max_num)
        {
            *max_index = index;
            max_num = num2;
        }
        num1 = num2;
    } while (fscanf(f, "%d", &num2) == EXIT_FAILURE);
    return EXIT_SUCCESS;
}

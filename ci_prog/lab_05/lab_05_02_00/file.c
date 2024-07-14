#include "file.h"

int find_average(FILE *f, double *aver)
{
    double num = 0;
    size_t len = 0;
    *aver = 0;
    while (fscanf(f, "%lf", &num) == 1)
    {
        *aver += num;
        len += 1;
    }
    if (feof(f) == IS_END)
    {
        return FILE_NOT_DEFINE;
    }
    if (len == 0)
    {
        return EMPTY_ERROR;
    }
    *aver = (*aver) / len;
    return EXIT_SUCCESS;
}

double find_closest(FILE *f, double aver)
{
    double num = 0;
    double closest = 0;
    double min_diff = DBL_MAX;
    fscanf(f, "%lf", &num);
    rewind(f);
    while (fscanf(f, "%lf", &num) == 1)
    {
        if (fabs(aver - num) < min_diff)
        {
            min_diff = fabs(aver - num);
            closest = num;
        }
    }
    if (feof(f) == IS_END)
    {
        return FILE_NOT_DEFINE;
    }
    return closest;
}

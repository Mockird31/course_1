#include "point.h"

int main(void)
{
    points_arr points;
    size_t len;
    int res = input_points(points, &len);
    if (res != EXIT_SUCCESS)
    {
        return res;
    }
    res = find_points(points, len);
    if (res != EXIT_SUCCESS)
    {
        return res;
    }
    return EXIT_SUCCESS;
}
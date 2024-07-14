#include "point.h"
#include "circle.h"

int main(void)
{
    points_t points;
    size_t len;
    points_t points_new;
    size_t new_len;
    int x_circ, y_circ, radius;
    int res = input_struct_arr(points, &len);
    if (res != EXIT_SUCCESS)
    {
        return res;
    }
    res = input_parametres(&x_circ, &y_circ, &radius);
    if (res != EXIT_SUCCESS)
    {
        return res;
    }
    res = check_points_inside(points, len, points_new, &new_len, x_circ, y_circ, radius);
    if (res != EXIT_SUCCESS)
    {
        return res;
    }
    for (size_t i = 0; i < new_len; i++)
    {
        print_struct(points_new[i]);
    }
    return EXIT_SUCCESS;
}
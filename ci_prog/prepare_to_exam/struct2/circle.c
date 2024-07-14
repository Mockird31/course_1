#include "circle.h"

int input_parametres(int *x, int *y, int *radius)
{
    if (scanf("%d", x) != 1)
    {
        return INPUT_ERROR;
    }
    if (scanf("%d", y) != 1)
    {
        return INPUT_ERROR;
    }
    if (scanf("%d", radius) != 1)
    {
        return INPUT_ERROR;
    }
    return EXIT_SUCCESS;
}

int check_in_circle(point_t point, int x_circ, int y_circ, int radius)
{
    int res = (int) (pow(point.x_coord - x_circ, 2) + pow(point.y_coord - y_circ, 2));
    int rad = (int) (pow(radius, 2));
    if (res - rad >= 0)
    {
        return EXIT_FAILURE; 
    }
    return EXIT_SUCCESS;
}

int check_points_inside(points_t points, size_t len, points_t points_new, size_t *new_len, int x_circ, int y_circ, int radius)
{
    *new_len = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (check_in_circle(points[i], x_circ, y_circ, radius) == EXIT_SUCCESS)
        {
            points_new[(*new_len)++] = points[i];
        }
    }
    if (*new_len == 0)
    {
        return NO_POINTS;
    }
    return EXIT_SUCCESS;
}
#include "point.h"

int input_string(char *str)
{
    char temp[MAX_NAME + 2];
    if (fgets(temp, MAX_NAME + 2, stdin) == NULL)
    {
        return INPUT_ERROR;
    }
    temp[strcspn(temp, "\n")] = '\0';
    if (strlen(temp) > MAX_NAME || strlen(temp) == 0)
    {
        return INPUT_ERROR;
    }
    strncpy(str, temp, MAX_NAME + 1);
    return EXIT_SUCCESS;
}

int input_one_point(point_t *point)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    int res = input_string(point->name);
    if (res != EXIT_SUCCESS)
    {
        return res;
    }
    if (scanf("%d", &point->x_coord) != 1)
    {
        return INPUT_ERROR;
    }
    if (scanf("%d", &point->y_coord) != 1)
    {
        return INPUT_ERROR;
    }
    return EXIT_SUCCESS;
}

int input_points(points_arr points, size_t *len)
{
    if (scanf("%zu", len) != 1)
    {
        return INPUT_ERROR;
    }
    int res;
    for (size_t i = 0; i < *len; i++)
    {
        res = input_one_point(&points[i]);
        if (res != EXIT_SUCCESS)
        {
            return res;
        }
    }
    return EXIT_SUCCESS;
}

void print_point(point_t point)
{
    printf("%s %d %d\n", point.name, point.x_coord, point.y_coord);
}

int is_triangle(point_t p1, point_t p2, point_t p3)
{
    double len1 = sqrt((pow(p1.x_coord, 2) - pow(p2.x_coord, 2)) + (pow(p1.y_coord, 2) - pow(p2.y_coord, 2)));
    double len2 = sqrt((pow(p1.x_coord, 2) - pow(p3.x_coord, 2)) + (pow(p1.y_coord, 2) - pow(p3.y_coord, 2)));
    double len3 = sqrt((pow(p3.x_coord, 2) - pow(p2.x_coord, 2)) + (pow(p3.y_coord, 2) - pow(p2.y_coord, 2)));
    return ((len1 + len2 > len3) && (len2 + len3 > len1) && (len1 + len3 > len2));
}

int find_square(point_t p1, point_t p2, point_t p3)
{
    return (int)(0.5 * abs(((p2.x_coord - p1.x_coord) * (p3.y_coord - p1.y_coord) - (p3.x_coord - p1.x_coord) * (p2.y_coord - p1.y_coord))));
}

int find_points(points_arr points, size_t len)
{
    int max_s = INT_MIN;
    point_t p1, p2, p3;
    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = i + 1; j < len; j++)
        {
            for (size_t k = j + 1; k < len; k++)
            {
                if ((!is_triangle(points[i], points[j], points[k])) && (find_square(points[i], points[j], points[k]) > max_s))
                {
                    max_s = find_square(points[i], points[j], points[k]);
                    p1 = points[i];
                    p2 = points[j];
                    p3 = points[k];
                }
            }
        }
    }
    print_point(p1);
    print_point(p2);
    print_point(p3);
    return EXIT_SUCCESS;
}

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

int input_struct(point_t *point)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
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

int input_struct_arr(points_t points, size_t *len)
{
    int res;
    if (scanf("%zu", len) != 1)
    {
        return INPUT_ERROR;
    }
    for (size_t i = 0; i < *len; i++)
    {
        res = input_struct(&points[i]);
        if (res != EXIT_SUCCESS)
        {
            return res;
        } 
    }
    return EXIT_SUCCESS;   
}

void print_struct(point_t point)
{
    printf("%s %d %d\n", point.name, point.x_coord, point.y_coord);
}
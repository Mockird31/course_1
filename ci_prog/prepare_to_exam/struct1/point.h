#ifndef _POINT_H_
#define _POINT_H_

#include <stdio.h>
#include <stdlib.h>
#include "code_errors.h"
#include <string.h>
#include <math.h>
#include <limits.h>

#define MAX_NAME 3
#define MAX_LEN 10

typedef struct 
{
    char name[MAX_NAME + 1];
    int x_coord;
    int y_coord;
} point_t;

typedef point_t points_arr[MAX_LEN];

int input_string(char *str);
int input_one_point(point_t *point);
int input_points(points_arr points, size_t *len);
void print_point(point_t point);
int is_triangle(point_t p1, point_t p2, point_t p3);
int find_square(point_t p1, point_t p2, point_t p3);
int find_points(points_arr points, size_t len);

#endif
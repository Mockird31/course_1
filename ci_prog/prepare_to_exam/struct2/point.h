#ifndef _POINT_H_
#define _POINT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "code_errors.h"

#define MAX_NAME 3
#define MAX_LEN 10

typedef struct
{
    char name[MAX_NAME + 1];
    int x_coord;
    int y_coord;
}point_t;

typedef point_t points_t[MAX_LEN];

int input_string(char *str);
int input_struct(point_t *point);
int input_struct_arr(points_t points, size_t *len);
void print_struct(point_t point);

#endif
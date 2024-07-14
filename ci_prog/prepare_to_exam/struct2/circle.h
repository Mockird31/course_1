#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "point.h"
#include <math.h>
#define EPS 0.01

int input_parametres(int *x, int *y, int *radius);
int check_in_circle(point_t point, int x_circ, int y_circ, int radius);
int check_points_inside(points_t points, size_t len, points_t points_new, size_t *new_len, int x_circ, int y_circ, int radius);

#endif
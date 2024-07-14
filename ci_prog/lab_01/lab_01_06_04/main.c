/**
 * @file main.c
 * @author Inyakin Roman (inyakinro@student.bmstu.ru)
 * @brief Checking whether a point belongs to a segment
 * @param[in] xp Float the coordinate x of the point P
 * @param[in] yp Float the coordinate y of the point P
 * @param[in] xq Float the coordinate x of the point Q
 * @param[in] yq Float the coordinate y of the point Q
 * @param[in] xr Float the coordinate x of the point R
 * @param[in] yr Float the coordinate y of the point R
 * @param[out] check_belong Int belonging of a point to a segment
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define POGRESH 0.00001

/**
 * @brief Checking whether a point belongs to a segment
 * @param[in] xp Float the coordinate x of the point P
 * @param[in] yp Float the coordinate y of the point P
 * @param[in] xq Float the coordinate x of the point Q
 * @param[in] yq Float the coordinate y of the point Q
 * @param[in] xr Float the coordinate x of the point R
 * @param[in] yr Float the coordinate y of the point R
 * @return Int 1 - belong, 0 - not belong
 */
int prinadlezhnost(float xp, float yp, float xq, float yq, float xr, float yr);

int main(void)
{
    float xq, yq, xr, yr;
    float xp, yp;
    int check_belong;

    printf("Enter xq and yq: ");
    if (scanf("%f%f", &xq, &yq) != 2)
    {
        printf("Input error\n");
        return 1;
    }

    printf("Enter xr and yr: ");
    if (scanf("%f%f", &xr, &yr) != 2)
    {
        printf("Input error\n");
        return 1;
    }

    printf("Enter xp and yp: ");
    if (scanf("%f%f", &xp, &yp) != 2)
    {
        printf("Input error\n");
        return 1;
    }

    if (((xr - xq) < POGRESH) && ((yr - yq) < POGRESH))
    {
        printf("It is a point\n");
        return 1;
    }

    check_belong = prinadlezhnost(xp, yp, xq, yq, xr, yr);

    printf("%d\n", check_belong);

    return 0;
}

int prinadlezhnost(float xp, float yp, float xq, float yq, float xr, float yr)
{
    float len_qr = sqrtf(powf((xr - xq), 2) + powf((yr - yq), 2));
    float len_qp = sqrtf(powf((xp - xq), 2) + powf((yp - yq), 2));
    float len_rp = sqrtf(powf((xp - xr), 2) + powf((yp - yr), 2));

    float diff = len_qp + len_rp;
    diff = fabsf(len_qr - diff);

    if (diff < POGRESH)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

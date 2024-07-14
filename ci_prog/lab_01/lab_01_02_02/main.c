/**
 * @file main.c
 * @author Inyakin Roman (inyakinro@student.bmstu.ru)
 * @brief Finding the perimeter of a triangle by the coordinates of its vertices
 * @version 0.1
 * @param[in] xa Float the x coordinate of point A
 * @param[in] ya Float the y coordinate of point A
 * @param[in] xb Float the x coordinate of point B
 * @param[in] yb Float the y coordinate of point B
 * @param[in] xc Float the x coordinate of point C
 * @param[in] yc Float the y coordinate of point C
 * @param[out] perimeter Float perimetr of a triangle
 */
#include <stdio.h>
#include <math.h>

int main(void)
{
    float xa, ya, xb, yb, xc, yc;
    float side1, side2, side3; // sides of a triangle
    float perimeter;

    printf("Enter the coordinate of the vertex A: ");
    if (scanf("%f%f", &xa, &ya) != 2)
    {
        printf("Input error\n");
        return 1;
    }

    printf("Enter the coordinate of the vertex B: ");
    if (scanf("%f%f", &xb, &yb) != 2)
    {
        printf("Input error\n");
        return 1;
    }

    printf("Enter the coordinate of the vertex C: ");
    if (scanf("%f%f", &xc, &yc) != 2)
    {
        printf("Input error\n");
        return 1;
    }

    side1 = sqrtf(powf((xa - xb), 2) + powf((ya - yb), 2));
    side2 = sqrtf(powf((xb - xc), 2) + powf((yb - yc), 2));
    side3 = sqrtf(powf((xc - xa), 2) + powf((yc - ya), 2));

    if ((side1 < side2 + side3) && (side2 < side1 + side3) && (side3 < side1 + side2))
    {
        perimeter = side1 + side2 + side3;
        printf("Perimeter: %f\n", perimeter);
        return 0;
    }
    else
    {
        printf("Nelzya postroit treugolnik s dannymi vershinami\n");
        return 1;
    }
}

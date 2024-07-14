/**
 * @file main.c
 * @author Inyakin Roman (inyakinro@student.bmstu.ru)
 * @brief Calculating the value of g(x), g(x) = (1/n) * (︀ sqrt(1+x1) + sqrt(2+x2) + ... + sqrt(n+xn))
 * @param[in] x Float the argument of the function g(x)
 * @param[out] g Float the value of function g(x)
 */

#include <stdio.h>
#include <math.h>

#define POGRESH 0.00001
/**
 * @brief Calculating the member of g(x)
 * @param[in] x Float the argument of the function g(x)
 * @param[in] n Int the number of arguments to the function
 * @param[out] memb Float the member of g(x)
 */
float count_g(float x, int n);

int main(void)
{
    float g = 0.0;
    float x = 0.0;
    int n = 1;

    while (1)
    {
        printf("Enter x: ");
        if (scanf("%f", &x) != 1)
        {
            printf("Input error\n");
            return 1;
        }

        if (x < 0 && g < POGRESH)
        {
            printf("No members\n");
            return 2;
        }
        else if (x < 0)
        {
            printf("Out from the loop\n");
            break;
        }
        g += count_g(x, n);
        n++;
    }

    g *= (float)(1.0 / (n - 1));
    printf("g(x) = %f\n", g);
    return 0;
}

float count_g(float x, int n)
{
    float memb;
    memb = sqrtf(n + x);
    return memb;
}

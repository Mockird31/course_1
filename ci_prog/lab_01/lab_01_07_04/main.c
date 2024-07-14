/**
 * @file main.c
 * @author Inyakin Roman (inyakinro@student.bmstu.ru)
 * @param[in] x Float function parameter f(x) and s(x)
 * @param[in] epsilon Float calculation accuracy
 * @param[out] f Float the value of the function f(x)
 * @param[out] s Float the value of the function s(x)
 * @param[out] d1 Float the value |f(x) - s(x)|
 * @param[out] d2 Float the value |f(x) - s(x)|/|f(x)|
 * @brief Calculating f(x), s(x), delta1, delta2 accordint to a given formula
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Calculating s(x) with epsilon precision
 * @param[in] x Float function parameter f(x) and s(x)
 * @param[in] epsilon Float calculation accuracy
 * @return s Float function s(x)
 */
float func_s(float x, float epsilon);

int main(void)
{
    float x;
    float epsilon;
    float f;
    float s;
    float d1;
    float d2;
    printf("Vvedite x i epsilon: ");
    if (scanf("%f%f", &x, &epsilon) != 2 || fabsf(x) >= 1.0 || epsilon <= 0.0 || epsilon > 1.0)
    {
        printf("Input error\n");
        return 1;
    }
    f = 1.0f / (float)(pow((x + 1), 3));
    s = func_s(x, epsilon);
    d1 = fabsf(f - s);
    d2 = (fabsf(f - s) / fabsf(f));
    printf("s(x): %f\n", s);
    printf("f(x): %f\n", f);
    printf("delta_one: %f\n", d1);
    printf("delta_two: %f\n", d2);
    return 0;
}

float func_s(float x, float epsilon)
{
    float s = 0.0;
    float temp = 1.0;
    int n = 1;
    while (fabsf(temp) >= epsilon)
    {
        s += temp;
        temp = 0.5f * (powf(x, n) * ((powf(-1, n)) * (1 + n) * (2 + n)));
        n++;
    }
    return s;
}

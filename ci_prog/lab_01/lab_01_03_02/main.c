/**
 * @file main.c
 * @author Inyakin Roman (inyakinro@student.bmstu.ru)
 * @brief Finding resistance of 3 resistors in parallel connection
 * @date 2024-02-14
 * @param[in] r1 Float the resistance of the first resistor
 * @param[in] r2 Float the resistance of the second resistor
 * @param[in] r3 Float the resistance of the third resistor
 * @param[out] main_r Float total resistance
 */

#include <stdio.h>

int main(void)
{
    float r1, r2, r3;
    printf("Vvedite soprotivlenie treh rezistorov: ");
    if (scanf("%f%f%f", &r1, &r2, &r3) != 3 || r1 <= 0 || r2 <= 0 || r3 <= 0)
    {
        printf("Input error\n");
        return 1;
    }
    float main_r = (1 / r1 + 1 / r2 + 1 / r3);
    printf("Soprotivlenie pri parallelnom soedinenii ravno %f \n", 1 / main_r);
    return 0;
}

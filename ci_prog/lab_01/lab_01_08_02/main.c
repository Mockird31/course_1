/**
 * @file main.c
 * @author Inyakin Roman (inyakinro@student.bmstu.ru)
 * @brief Cyclic left shift and binary output
 * @param[in] a Uint32_t an unsigned integer 4 bytes long
 * @param[in] n Int an integer to be shifted to the left
 * @param[out] a Uint32_t the modified number in the binary number system
 */

#include <stdio.h>
#include <stdint.h>

#define NUMBER_0F_BITS 32
/**
 * @brief Conversion to the binary number system
 * @param[in] a Unsigned int
 */
void print_dv_sys(uint32_t number);

int main(void)
{
    uint32_t a;
    int n;
    int t1, t2;
    printf("Enter a and n: ");
    if (scanf("%u%d", &a, &n) != 2 || n < 0)
    {
        printf("Error: ");
        printf("Input error\n");
        return 1;
    }
    n %= NUMBER_0F_BITS;
    t1 = a << n;
    t2 = a >> (NUMBER_0F_BITS - n);
    a = t1 | t2;
    printf("Result: ");
    print_dv_sys(a);
    return 0;
}

void print_dv_sys(uint32_t a)
{
    for (int i = NUMBER_0F_BITS-1; i >= 0; i--)
    {
        printf("%u", (a >> i) & 1);
    }
    printf("\n");
}

/**
 * @file main.c
 * @author Inyakin Roman (inyakinro@student.bmstu.ru)
 * @brief Decomposing a number into prime factors
 * @date 2024-02-14
 */

#include <stdio.h>

/**
 * @brief Decomposing a number into prime factors
 * @param[in] n Int the number entered by the user
 * @return Prime factors
 */
void find_prost_del(int n);

int main(void)
{
    int n;
    printf("Vvedite naturalnoe chislo: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Input error\n");
        return 1;
    }
    if (n == 1)
    {
        return 0;
    }
    printf("Prostye mnozhiteli: ");
    find_prost_del(n);

    return 0;
}

void find_prost_del(int n)
{
    while (n % 2 == 0)
    {
        printf("%d ", 2);
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            printf("%d ", i);
            n /= i;
        }
    }

    if (n > 2)
    {
        printf("%d ", n);
    }
    printf("\n");
}

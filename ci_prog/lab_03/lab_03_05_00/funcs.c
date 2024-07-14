#include "funcs.h"

int is_prime(int n)
{
    int counter = 0;
    if (n <= 1)
    {
        return FAIL_PRIME;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            counter++;
        }
    }
    if (counter != 0)
    {
        return FAIL_PRIME;
    }
    return SUCCESS;
}

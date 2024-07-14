#include "funcs.h"
#include <stdlib.h>

int sum_cif(int n)
{
    n = abs(n);
    int res = 0;
    while (n > 0)
    {
        res += n % DELIT;
        n = n / DELIT;
    }
    return res;
}

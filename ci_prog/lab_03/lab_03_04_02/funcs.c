#include "funcs.h"

int check_last(int n)
{
    n = abs(n);
    int res;
    res = n % DELIT;
    if (res != LAST_NUM)
    {
        return ERROR_LAST_NUM;
    }
    return SUCCESS;
}

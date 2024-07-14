#include "my_string.h"

int main(void)
{
    char str[MAX_LEN + 1];
    int sum = 0;
    int res = input_string(str);
    if (res != EXIT_SUCCESS)
    {
        return res;
    }
    res = count_num(str, &sum);
    if (res != EXIT_SUCCESS)
    {
        return res;
    }
    printf("%d\n", sum);
    return EXIT_SUCCESS;
}
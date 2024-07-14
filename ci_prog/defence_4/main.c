#include "my_string.h"

int main(void)
{
    char str[MAX_STR];
    int res1 = input_string(str);
    if (res1 != EXIT_SUCCESS)
    {
        return res1;
    }
    int res2 = check_skob(str);
    if (res2 == EXIT_SUCCESS)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return EXIT_SUCCESS;
}
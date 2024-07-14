#include "my_string.h"

int main(void)
{
    char str[MAX_STR];
    char date[MAX_COUNT][MAX_WORD + 1];
    size_t len;
    int res1;
    int res2;
    int res3;
    res1 = input_strings(str);
    if (res1 != EXIT_SUCCESS)
    {
        return res1;
    }
    res2 = split(str, date, &len);
    if (res2 != EXIT_SUCCESS)
    {
        printf("NO\n");
        return EXIT_SUCCESS;
    }
    res3 = check_full_date(date);
    if (res3 == EXIT_SUCCESS)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return EXIT_SUCCESS;
}

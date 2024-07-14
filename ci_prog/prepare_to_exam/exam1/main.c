#include "my_string.h"

int main(void)
{
    char str[MAX_LEN];
    char words[MAX_LEN][MAX_LEN];
    size_t len;
    int res = input_string(str);
    if (res != EXIT_SUCCESS)
    {
        return res;
    }
    res = split(str, words, &len);
    if (res != EXIT_SUCCESS)
    {
        return res;
    }
    for (size_t i = 0; i < len; i++)
    {
        reverse(words[i]);
    }
    join(words, len, str);
    printf("%s\n", str);
    return EXIT_SUCCESS;
}
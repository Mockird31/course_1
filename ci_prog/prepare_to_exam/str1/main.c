#include "my_string.h"


int main(void)
{
    char str[MAX_LEN + 1];
    size_t len;
    char words[MAX_LEN][MAX_WORD];
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
    res = replace_max_and_min(words, len);
    if (res != EXIT_SUCCESS)
    {
        return res;
    }
    join(str, words, len);
    printf("%s\n", str);
    return EXIT_SUCCESS;
}
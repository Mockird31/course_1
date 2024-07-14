#include "my_string.h"

int main(void)
{
    char str[MAX_STR + 1];
    int res = input_string(str);
    words_t words;
    size_t len;
    if (res != EXIT_SUCCESS)
    {
        return res;
    }
    res = split(str, words, &len);
    if (res != EXIT_SUCCESS)
    {
        return res;
    }
    res = reverse_in_arr(words, len);
    if (res != EXIT_SUCCESS)
    {
        return res;
    }
    join(words, len, str);
    printf("%s\n", str);
    return EXIT_SUCCESS;
}
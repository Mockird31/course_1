#include "my_string.h"

int main(void)
{
    char str[MAX_STR];
    char res[MAX_STR];
    char words[MAX_COUNT][MAX_WORD + 1];
    char new_words[MAX_COUNT][MAX_WORD + 1];
    size_t len;
    size_t new_len;
    int res1 = input_strings(str);
    if (res1 != SUCCESS)
    {
        return res1;
    }
    int res2 = split(str, words, &len);
    if (res2 != SUCCESS)
    {
        return res2;
    }
    make_unique(words, len, new_words, &new_len);
    int res3 = join(res, new_words, new_len);
    if (res3 != SUCCESS)
    {
        return res3;
    }
    printf("Result: %s\n", res);
    return SUCCESS;
}

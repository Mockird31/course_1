#include "my_string.h"

int main(void)
{
    char str1[MAX_STR];
    char str2[MAX_STR];
    char words1[MAX_COUNT][MAX_WORD + 1];
    char words2[MAX_COUNT][MAX_WORD + 1];
    char unique_words[MAX_COUNT][MAX_WORD + 1];
    int res1, res2, res3;
    size_t len1, len2, unique_len;
    if (input_strings(str1) != SUCCESS || input_strings(str2) != SUCCESS)
    {
        return INPUT_ERROR;
    }
    res1 = split(str1, words1, &len1);
    if (res1 != SUCCESS)
    {
        return res1;
    }
    make_unique(words1, len1, unique_words, &unique_len);
    res2 = split(str2, words2, &len2);
    if (res2 != SUCCESS)
    {
        return res2;
    }
    res3 = in_other(unique_words, words2, unique_len, len2);
    if (res3 != SUCCESS)
    {
        return res3;
    }
    return SUCCESS;
}

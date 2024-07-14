#include "my_string.h"

int input_strings(char *str)
{
    printf("Input the string: \n");
    char temp[MAX_STR + 2];
    if (fgets(temp, MAX_STR + 2, stdin) == NULL)
    {
        return INPUT_ERROR;
    }
    temp[strcspn(temp, "\n")] = '\0';
    if ((strlen(temp) && strlen(temp) > MAX_STR) || (strlen(temp) == 0))
    {
        printf("Input error\n");
        return INPUT_ERROR;
    }
    strncpy(str, temp, MAX_STR);
    return SUCCESS;
}

int is_word_in_array(char *word, char new_words[MAX_COUNT][MAX_WORD + 1], size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        if (strcmp(new_words[i], word) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void make_unique(char words[MAX_COUNT][MAX_WORD + 1], size_t len, char new_words[MAX_COUNT][MAX_WORD + 1], size_t *new_len)
{
    *new_len = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (!is_word_in_array(words[i], new_words, *new_len))
        {
            strcpy(new_words[(*new_len)++], words[i]);
        }
    }
}

int split(char *str, char words[MAX_COUNT][MAX_WORD + 1], size_t *len)
{
    *len = 0;
    int word_length = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        if (strchr(SEPS, str[i]) != NULL)
        {
            if (word_length > 0)
            {
                words[(*len)++][word_length] = '\0';
                word_length = 0;
            }
        }
        else
        {
            if (word_length < MAX_WORD)
            {
                words[*len][word_length++] = str[i];
            }
        }
        i++;
    }
    if (word_length > 0)
    {
        words[(*len)++][word_length] = '\0';
    }
    return SUCCESS;
}

int in_other(char words1[MAX_COUNT][MAX_WORD + 1], char words2[MAX_COUNT][MAX_WORD + 1], size_t len1, size_t len2)
{
    if (len1 == 0 || len2 == 0)
    {
        return NO_WORDS;
    }
    printf("Result: ");
    for (size_t i = 0; i < len1; i++)
    {
        int flag = 0;
        for (size_t j = 0; j < len2; j++)
        {
            if (strcmp(words1[i], words2[j]) == 0)
            {
                flag = 1;
            }
        }
        if (flag)
        {
            printf("%s yes\n", words1[i]);
        }
        else
        {
            printf("%s no\n", words1[i]);
        }
    }
    return SUCCESS;
}
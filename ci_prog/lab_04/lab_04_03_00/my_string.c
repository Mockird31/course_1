#include "my_string.h"

int input_strings(char *str)
{
    char temp[MAX_STR + 2];
    if (fgets(temp, MAX_STR + 2, stdin) == NULL)
    {
        return INPUT_ERROR;
    }
    temp[strcspn(temp, "\n")] = '\0';
    if ((strlen(temp) && strlen(temp) > MAX_STR) || (strlen(temp) == 0))
    {
        return INPUT_ERROR;
    }
    strncpy(str, temp, MAX_STR);
    return SUCCESS;
}

int split(char *str, char words[MAX_COUNT][MAX_WORD + 1], size_t *len)
{
    *len = 0;
    char *token = strtok(str, SEPS);
    while (token != NULL)
    {
        if (*len < MAX_WORD)
        {
            strcpy(words[(*len)++], token);
            token = strtok(NULL, SEPS);
        }
        else
        {
            return ERROR_WORD_COUNT;
        }
    }
    return SUCCESS;
}

void make_unique(char words[MAX_COUNT][MAX_WORD + 1], size_t len, char new_words[MAX_COUNT][MAX_WORD + 1], size_t *new_len)
{
    char *last_words = words[len - 1];
    *new_len = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (strcmp(words[i], last_words) != 0)
        {
            strcpy(new_words[(*new_len)++], words[i]);
        }
    }
}

void del_first_symb(char *word, char *new_word)
{
    size_t len = 1;
    new_word[0] = word[0];
    char symb = word[0];
    for (size_t i = 0; word[i] != '\0'; i++)
    {
        if (word[i] != symb)
        {
            new_word[len++] = word[i];
        }
    }
    new_word[len] = '\0';
}

int join(char *res, char words[MAX_COUNT][MAX_WORD + 1], int len)
{
    if (len == 0)
    {
        return NO_WORDS;
    }
    char new_word[MAX_WORD + 1];
    for (int i = 0; i < len; i++)
    {
        strcpy(new_word, "");
        del_first_symb(words[i], new_word);
        strcpy(words[i], new_word);
    }
    strcpy(res, "");
    for (int i = len - 1; i >= 0; i--)
    {
        strcat(res, words[i]);
        strcat(res, " ");
    }
    res[strlen(res) - 1] = '\0';
    return SUCCESS;
}

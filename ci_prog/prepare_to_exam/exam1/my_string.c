#include "my_string.h"

int input_string(char *str)
{
    char temp[MAX_LEN + 2];
    if (fgets(temp, MAX_LEN + 2, stdin) == NULL)
    {
        return ERROR_INPUT;
    }
    temp[strcspn(temp, "\n")] = '\0';
    if ((strlen(temp) && strlen(temp) > MAX_LEN) || (strlen(temp) == 0))
    {
        return ERROR_INPUT;
    }
    strncpy(str, temp, MAX_LEN + 1);
    return EXIT_SUCCESS;
}

int split(char *str, char words[MAX_LEN][MAX_LEN], size_t *len)
{
    *len = 0;
    char *word = strtok(str, SEPS);
    while (word != NULL)
    {
        if (*len < MAX_LEN)
        {
            strcpy(words[(*len)++], word);
            word = strtok(NULL, SEPS);
        }
        else 
        {
            return ERROR_COUNT;
        }
    }
    return EXIT_SUCCESS;
}

void reverse(char *word)
{
    char buf;
    for (size_t i = 0; i < (strlen(word) / 2); i++)
    {
        buf = word[i];
        word[i] = word[strlen(word) - i - 1];
        word[strlen(word) - i - 1] = buf;
    }
}

int join(char words[MAX_LEN][MAX_LEN], size_t len, char *str)
{
    if (len == 0)
    {
        return NO_WORDS;
    }
    strcpy(str, "");
    for (size_t i = 0; i < len; i++)
    {
        strcat(str, words[i]);
        strcat(str, " ");
    }
    str[strlen(str) - 1] = '\0';
    return EXIT_SUCCESS;
}
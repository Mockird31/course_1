#include "my_string.h"

int input_string(char *str)
{
    char temp[MAX_STR + 2];
    if (fgets(temp, MAX_STR + 2, stdin) == NULL)
    {
        return INPUT_ERROR;
    }
    temp[strcspn(temp, "\n")] = '\0';
    if (strlen(temp) > MAX_STR && strlen(temp) == 0)
    {
        return INPUT_ERROR;
    }
    strncpy(str, temp, MAX_STR + 1);
    return EXIT_SUCCESS;
}

int split(char *str, words_t words, size_t *len)
{
    *len = 0;
    char *word = strtok(str, SEPS);
    while (word != NULL)
    {
        if (*len > (MAX_STR / 2))
        {
            return ERR_OVERFLOW;
        }
        strcpy(words[(*len)++], word);
        word = strtok(NULL, SEPS);
    }
    return EXIT_SUCCESS;
}

int is_numeric(char *str)
{
    while(*str)
    {
        if (!isdigit(*str))
        {
            return NOT_NUM;
        }
        str++;
    }
    return EXIT_SUCCESS;
}

int reverse_in_arr(words_t words, size_t len)
{
    size_t counter = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (is_numeric(words[i]) == EXIT_SUCCESS)
        {
            reverse(words[i]);
            counter++;
        }
    }
    if (counter == 0)
        return NO_NUMS;
    return EXIT_SUCCESS;
}

void reverse(char *str)
{
    char temp;
    for(size_t i = 0; i < strlen(str)/2; i++)
    {
        temp = str[strlen(str) - i - 1];
        str[strlen(str) - i - 1] = str[i];
        str[i] = temp;
    }
}

void join(words_t words, size_t len, char *str)
{
    strcpy(str, "");
    for (size_t i = 0; i < len; i++)
    {
        strcat(str, words[i]);
        strcat(str, " ");
    }
    str[strlen(str)] = '\0';
}
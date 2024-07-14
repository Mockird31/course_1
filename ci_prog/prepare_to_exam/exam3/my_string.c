#include "my_string.h"

int input_string(char *str)
{
    char temp[MAX_LEN + 2];
    if (fgets(temp, MAX_LEN + 2, stdin) == NULL)
    {
        return INPUT_ERROR;
    }
    temp[strcspn(temp, "\n")] = '\0';
    if (strlen(temp) == 0)
    {
        return ERR_EMPTY;
    }
    if (strlen(temp) > MAX_LEN)
    {
        return ERR_OVERFLOW;
    }
    strncpy(str, temp, MAX_LEN + 1);
    return EXIT_SUCCESS;
}

int count_num(char *str, int *sum)
{
    char *word = strtok(str, SEPS);
    while (word != NULL)
    {
        if (is_number(word) == EXIT_SUCCESS)
        {
            *sum += str_to_num(word);
        }
        word = strtok(NULL, SEPS);
    }
    if (*sum == 0)
    {
        return ERR_NO_DATA;
    }
    return EXIT_SUCCESS;
}

int is_number(char *str)
{
    while (*str)
    {
        if (!isdigit(*str))
        {
            return EXIT_FAILURE;
        }
        str++;
    }
    return EXIT_SUCCESS;
    
}

int str_to_num(char *word)
{
    int num = 0;
    while (*word)
    {
        num = num * 10 + (*word - '0');
        word++;
    }
    return num;
}


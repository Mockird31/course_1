#include "my_string.h"

int input_string(char *str)
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
    return EXIT_SUCCESS;
}

int check_skob(char *str)
{
    size_t count_open = 0;
    size_t count_close = 0;
    int in_side = 0;
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(')
        {
            count_open += 1;
            in_side = 1;
        }
        if (str[i] == ')')
        {
            count_close += 1;
            in_side = 0;
        }
    }
    if (count_open == count_close && in_side == 0)
    {
        return EXIT_SUCCESS;
    }
    else
    {
        return EXIT_FAILURE;
    }
}

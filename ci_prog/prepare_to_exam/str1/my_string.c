#include "my_string.h"

int input_string(char *str)
{
    char temp[MAX_LEN + 2];
    if (fgets(temp, MAX_LEN + 2, stdin) == NULL)
    {
        return INPUT_ERROR;
    }
    temp[strcspn(temp, "\n")] = '\0';
    if (strlen(temp) > MAX_LEN || strlen(temp) == 0)
    {
        return INPUT_ERROR;
    }
    strncpy(str, temp, MAX_LEN + 1);
    return EXIT_SUCCESS;
}

int split(char *str, char words[MAX_LEN][MAX_WORD], size_t *len)
{
    *len = 0;
    char *token = strtok(str, SEPS);
    while (token != NULL)
    {
        if (*len < MAX_LEN)
        {
            strcpy(words[(*len)++], token);
            token = strtok(NULL, SEPS);
        }
        else
        {
            return SIZE_ERROR;
        }
    }
    return EXIT_SUCCESS;
}

int is_numeric(char *str)
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

int replace_max_and_min(char words[MAX_LEN][MAX_WORD], size_t len)
{
    int max = INT_MIN;
    int min = INT_MAX;
    int pos_max = 0, pos_min = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (is_numeric(words[i]) == EXIT_SUCCESS)
        {
            if (str_to_num(words[i]) > max)
            {
                max = str_to_num(words[i]);
                pos_max = i;
            }
        }
    }
    for (size_t i = 0; i < len; i++)
    {
        if (is_numeric(words[i]) == EXIT_SUCCESS)
        {
            if (str_to_num(words[i]) < min)
            {
                min = str_to_num(words[i]);
                pos_min = i;
            }
        }
    }
    if (max == INT_MIN || min == INT_MAX)
        return INPUT_ERROR;
    swap(words[pos_max], words[pos_min]);
    return EXIT_SUCCESS;
}

int str_to_num(char *str)
{
    int num = 0;
    while (*str)
    {
        num = num * 10 + (*str - '0');
        str++;
    }
    return num;
}

int join(char *str, char words[MAX_LEN][MAX_WORD], size_t len)
{
    strcpy(str, "");
    for (size_t i = 0; i < len; i++)
    {
        strcat(str, words[i]);
        strcat(str, " ");
    }
    str[strlen(str) - 1] = '\0';
    return EXIT_SUCCESS;
}

void swap(char *str1, char *str2)
{
    char buf[MAX_WORD];
    strcpy(buf, str1);
    strcpy(str1, str2);
    strcpy(str2, buf);
}
#include "my_string.h"

char *my_strpbrk(const char *str1, const char *str2)
{
    for (size_t i = 0; str1[i] != '\0'; i++)
    {
        for (size_t j = 0; str2[j] != '\0'; j++)
        {
            if (str1[i] == str2[j])
            {
                return (char *)&str1[i];
            }
        }
    }
    return NULL;
}

size_t my_strspn(const char *str1, const char *str2)
{
    size_t counter = 0;
    int state = 1;
    for (size_t i = 0; str2[i] != '\0'; i++)
    {
        if (str1[0] == str2[i])
        {
            state = 0;
        }
    }
    if (state == 1)
    {
        return counter;
    }
    for (size_t i = 0; str1[i] != '\0'; i++)
    {
        int flag = 0;
        for (size_t j = 0; str2[j] != '\0'; j++)
        {
            if (str1[i] == str2[j])
            {
                flag = 1;
            }
        }
        if (flag == 1)
        {
            counter++;
        }
        else
        {
            return counter;
        }
    }
    return counter;
}

size_t my_strcspn(const char *str1, const char *str2)
{
    size_t pos = 0;
    for (size_t i = 0; str1[i] != '\0'; i++)
    {
        for (size_t j = 0; str2[j] != '\0'; j++)
        {
            if (str1[i] == str2[j])
            {
                return pos;
            }
        }
        pos++;
    }
    return pos;
}

char *my_strchr(const char *str, int symbol)
{
    size_t i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == symbol)
        {
            return (char *)&str[i];
        }
        i++;
    }
    if (symbol == '\0')
    {
        return (char *)&str[i];
    }
    return NULL;
}

char *my_strrchr(const char *str, int symbol)
{
    char *res = NULL;
    size_t i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == symbol)
        {
            res = (char *)&str[i];
        }
        i++;
    }
    if (symbol == '\0')
    {
        return (char *)&str[i];
    }
    return res;
}

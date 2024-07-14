/**
 * @file check_date.c
 * @author Инякин Роман
 * @brief Функции для проверки даты и времени
 * @version 0.1
 * @date 2024-06-05
 * 
 */

#include "check_date.h"

int input_strings(char *str)
{
    char temp[MAX_STR + 2];
    if (fgets(temp, MAX_STR + 2, stdin) == NULL)
    {
        return INPUT_ERROR;
    }
    temp[strcspn(temp, "\n")] = '\0';
    if ((strlen(temp) && strlen(temp) > MAX_STR))
    {
        return INPUT_ERROR;
    }
    strncpy(str, temp, MAX_STR);
    return EXIT_SUCCESS;
}

void ltrim(char *str)
{
    int i = 0, j = 0;
    while (str[i] != '\0')
    {
        if (!isspace(str[i]))
        {
            break;
        }
        i++;
    }
    while (str[i] != '\0')
    {
        str[j] = str[i];
        i++;
        j++;
    }
    str[j] = '\0';
}

void rtrim(char *str)
{
    int i = strlen(str) - 1;
    while (i >= 0)
    {
        if (!isspace(str[i]))
        {
            break;
        }
        i--;
    }
    str[i + 1] = '\0';
}

int split(char *str, char words[MAX_COUNT][MAX_WORD + 1], size_t *len)
{
    ltrim(str);
    rtrim(str);
    *len = 0;
    char *token = strtok(str, SEPS);
    while (token != NULL)
    {
        strcpy(words[(*len)++], token);
        token = strtok(NULL, SEPS);
    }
    if (*len > 3 || *len == 0 || *len < 3)
    {
        return WRONG_DATE;
    }
    return EXIT_SUCCESS;
}

void make_lower(char *str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
    }
}

int check_month(char *month)
{
    make_lower(month);
    if (strstr(MONTHES, month) == NULL)
    {
        return WRONG_DATE;
    }
    return EXIT_SUCCESS;
}

int is_integer(char *str)
{
    if (strlen(str) == 0)
    {
        return WRONG_DATE;
    }
    for (size_t i = 0; i < strlen(str); i++)
    {
        if (!isdigit(str[i]))
        {
            return WRONG_DATE;
        }
    }
    return EXIT_SUCCESS;
}

int check_day(char *day)
{
    if (is_integer(day) != EXIT_SUCCESS)
    {
        return WRONG_DATE;
    }
    int int_day = atoi(day);
    if ((int_day <= 0) || (int_day > 31))
    {
        return WRONG_DATE;
    }
    return EXIT_SUCCESS;
}

int check_year(char *year)
{
    if (is_integer(year) != EXIT_SUCCESS)
    {
        return WRONG_DATE;
    }
    int int_year = atoi(year);
    if (int_year < 1924 || int_year > 2024)
    {
        return WRONG_DATE;
    }
    return EXIT_SUCCESS;
}

int is_leap_year(char *year)
{
    if (check_year(year) != EXIT_SUCCESS)
    {
        return WRONG_DATE;
    }
    int int_year = atoi(year);
    if (int_year % 400 == 0)
    {
        return EXIT_SUCCESS;
    }
    else if (int_year % 100 == 0)
    {
        return WRONG_DATE;
    }
    else if (int_year % 4 == 0)
    {
        return EXIT_SUCCESS;
    }
    else
    {
        return WRONG_DATE;
    }
}

int check_correct(char date[MAX_COUNT][MAX_WORD + 1])
{
    if (check_day(date[0]) != EXIT_SUCCESS)
    {
        return WRONG_DATE;
    }
    if (check_month(date[1]) != EXIT_SUCCESS)
    {
        return WRONG_DATE;
    }
    if (check_year(date[2]) != EXIT_SUCCESS)
    {
        return WRONG_DATE;
    }
    return EXIT_SUCCESS;
}

int check_full_date(char date[MAX_COUNT][MAX_WORD + 1])
{
    char *days31 = "января марта мая июля августа октября декабря";
    char *days30 = "апреля июня сентября ноября";
    int day = atoi(date[0]);
    make_lower(date[1]);
    if (check_correct(date) != EXIT_SUCCESS)
    {
        return WRONG_DATE;
    }
    if (strcmp(date[1], "февраля") == 0 && is_leap_year(date[2]) == EXIT_SUCCESS && day <= 29)
    {
        return EXIT_SUCCESS;
    }
    if (strcmp(date[1], "февраля") == 0 && is_leap_year(date[2]) != EXIT_SUCCESS && day <= 28)
    {
        return EXIT_SUCCESS;
    }
    if (strstr(days31, date[1]) != NULL && day <= 31)
    {
        return EXIT_SUCCESS;
    }
    if (strstr(days30, date[1]) != NULL && day <= 30)
    {
        return EXIT_SUCCESS;
    }
    return WRONG_DATE;
}

int monthToNumber(const char *month)
{
    const char *months[] = {
        "января", "февраля", "марта", "апреля", "мая", "июня",
        "июля", "августа", "сентября", "октября", "ноября", "декабря"};
    for (size_t i = 0; i < NUMS_OF_MONTHES; ++i)
    {
        if (strcmp(month, months[i]) == 0)
        {
            return i + 1;
        }
    }
    return -1;
}

int compareDates(char date1[MAX_COUNT][MAX_WORD + 1], char date2[MAX_COUNT][MAX_WORD + 1])
{
    if (atoi(date1[2]) > atoi(date2[2]))
    {
        return FIRST_DATE_LATER;
    }
    else if (atoi(date1[2]) < atoi(date2[2]))
    {
        return SECOND_DATE_LATER;
    }

    int month1 = monthToNumber(date1[1]);
    int month2 = monthToNumber(date2[1]);

    if (month1 > month2)
    {
        return FIRST_DATE_LATER;
    }
    else if (month1 < month2)
    {
        return SECOND_DATE_LATER;
    }

    if (atoi(date1[0]) > atoi(date2[0]))
    {
        return FIRST_DATE_LATER;
    }
    else if (atoi(date1[0]) < atoi(date2[0]))
    {
        return SECOND_DATE_LATER;
    }

    return DATE_EQUALS;
}

int parse_time(const char *time, uint16_t *hour, uint16_t *minute)
{
    if (sscanf(time, "%hu:%hu", hour, minute) != 2)
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int compare_time(const char *time1, const char *time2)
{
    uint16_t hour1, minute1, hour2, minute2;
    int res = parse_time(time1, &hour1, &minute1);
    if (res != EXIT_SUCCESS)
    {
        return res;
    }
    res = parse_time(time2, &hour2, &minute2);
    if (res != EXIT_SUCCESS)
    {
        return res;
    }
    if (hour1 > hour2)
    {
        return FIRST_DATE_LATER;
    }
    else if (hour1 < hour2)
    {
        return SECOND_DATE_LATER;
    }

    if (minute1 > minute2)
    {
        return FIRST_DATE_LATER;
    }
    else if (minute1 < minute2)
    {
        return SECOND_DATE_LATER;
    }
    return DATE_EQUALS;
}

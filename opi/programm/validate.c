/**
 * @file validate.c
 * @author Инякин Роман
 * @brief Функции для проверки входных данных
 * @version 0.1
 * @date 2024-06-05
 * 
 */
#include "validate.h"

bool validateGenre(const char *genre)
{
    const char *allowedGenres[MAX_GENRES] = {"комедия", "семейное кино", "триллер", "боевик", "мелодрама"};
    for (int i = 0; i < MAX_GENRES; i++)
    {
        if (strcmp(genre, allowedGenres[i]) == 0)
        {
            return true;
        }
    }
    return false;
}

bool validateYear(int year)
{
    return (year >= YEAR_MIN && year <= YEAR_MAX);
}

bool validateDuration(int duration)
{
    return (duration >= DUR_MIN && duration <= DUR_MAX);
}

bool validateAgeRestriction(const char *age_restriction)
{
    const char *allowedAgeRestrictions[AGE_RESTRICTION_LEN] = {"0+", "6+", "12+", "16+", "18+"};
    for (int i = 0; i < AGE_RESTRICTION_LEN; i++)
    {
        if (strcmp(age_restriction, allowedAgeRestrictions[i]) == 0)
        {
            return true;
        }
    }
    return false;
}

bool validateTime(const char *time)
{
    int hour, minute;
    if (sscanf(time, "%d:%d", &hour, &minute) != 2)
    {
        return false;
    }
    return (hour >= HOUR_MIN && hour <= HOUR_MAX) && (minute >= MINUTE_MIN && minute <= MINUTE_MAX);
}

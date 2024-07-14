/**
 * @file movie.c
 * @author Инякин Роман
 * @brief Функции для работы с афишей кинотеатра
 * @version 0.1
 * @date 2024-06-05
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "movie.h"

int readMovies(MovieScreening movies[], size_t *count)
{
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL)
    {
        printf("Файла не существует\n");
        return EXIT_FAILURE;
    }

    while (fscanf(file, "%99[^,],%99[^,],%99[^,],%d,%49[^,],%d,%99[^,],%99[^,],%99[^,],%5[^\n]\n",
                  movies[*count].movie.title,
                  movies[*count].movie.genre,
                  movies[*count].movie.director,
                  &movies[*count].movie.year,
                  movies[*count].movie.country,
                  &movies[*count].movie.duration,
                  movies[*count].movie.age_restriction,
                  movies[*count].cinema,
                  movies[*count].date,
                  movies[*count].time) != EOF)
    {
        (*count)++;
    }
    fclose(file);
    return EXIT_SUCCESS;
}

int saveMovies(MovieScreening movies[], size_t count)
{
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL)
    {
        printf("Неудается сохранить данные\n");
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < count; i++)
    {
        fprintf(file, "%s,%s,%s,%d,%s,%d,%s,%s,%s,%s\n",
                movies[i].movie.title,
                movies[i].movie.genre,
                movies[i].movie.director,
                movies[i].movie.year,
                movies[i].movie.country,
                movies[i].movie.duration,
                movies[i].movie.age_restriction,
                movies[i].cinema,
                movies[i].date,
                movies[i].time);
    }
    fclose(file);
    return EXIT_SUCCESS;
}

int addMovie(MovieScreening movies[], size_t *count)
{
    if (*count >= MAX_RECORDS)
    {
        printf("Нельзя добавить фильм, база данных переполнена\n");
        return EXIT_FAILURE;
    }

    printf("Введите название фильма: ");
    fgets(movies[*count].movie.title, MAX_LEN, stdin);
    strtok(movies[*count].movie.title, "\n"); 

    printf("Введите жанр: ");
    fgets(movies[*count].movie.genre, MAX_LEN, stdin);
    strtok(movies[*count].movie.genre, "\n");
    if (!validateGenre(movies[*count].movie.genre))
    {
        printf("Неверный жанр.\n");
        return EXIT_FAILURE;
    }

    printf("Введите фамилию режиссера: ");
    fgets(movies[*count].movie.director, MAX_LEN, stdin);
    strtok(movies[*count].movie.director, "\n");

    printf("Введите год выхода: ");
    scanf("%d", &movies[*count].movie.year);
    if (!validateYear(movies[*count].movie.year))
    {
        printf("Неверный год, он должен находиться в диапазоне от 1924 до 2024!\n");
        return EXIT_FAILURE;
    }
    getchar();

    printf("Введите страну: ");
    fgets(movies[*count].movie.country, MAX_LEN, stdin);
    strtok(movies[*count].movie.country, "\n");

    printf("Введите длительность (в минутах): ");
    scanf("%d", &movies[*count].movie.duration);
    if (!validateDuration(movies[*count].movie.duration))
    {
        printf("Неверная длительность, она должна находиться в диапазоне от 40 до 180 минут\n");
        return EXIT_FAILURE;
    }
    getchar();

    printf("Введите возрастное ограничение: ");
    fgets(movies[*count].movie.age_restriction, MAX_LEN, stdin);
    strtok(movies[*count].movie.age_restriction, "\n");
    if (!validateAgeRestriction(movies[*count].movie.age_restriction))
    {
        printf("Неверное возрастное ограничение!\n");
        return EXIT_FAILURE;
    }

    printf("Введите название кинотеатра: ");
    fgets(movies[*count].cinema, MAX_LEN, stdin);
    strtok(movies[*count].cinema, "\n");

    printf("Введите дату показа (ДД месяц ГГГГ): ");
    fgets(movies[*count].date, MAX_LEN, stdin);
    strtok(movies[*count].date, "\n");
    char date[MAX_COUNT][MAX_WORD + 1];
    size_t len;
    char temp[MAX_LEN];
    strncpy(temp, movies[*count].date, MAX_LEN);
    int res = split(temp, date, &len);
    if (res != EXIT_SUCCESS)
    {
        return EXIT_FAILURE;
    }
    if (check_full_date(date) != EXIT_SUCCESS)
    {
        printf("Неверная дата\n");
        return EXIT_FAILURE;
    }

    printf("Введите время показа (ЧЧ:ММ): ");
    fgets(movies[*count].time, MAX_LEN, stdin);
    strtok(movies[*count].time, "\n");
    if (!validateTime(movies[*count].time))
    {
        printf("Неверное время.\n");
        return EXIT_FAILURE;
    }

    (*count)++;
    printf("Фильм успешно добавлен\n");
    return EXIT_SUCCESS;
}

int deletePassedMovies(MovieScreening movies[], size_t *count)
{
    char currentDate[MAX_LEN];
    char currentTime[MAX_LEN];
    printf("Введите текущую дату (ДД месяц ГГГГ): ");
    fgets(currentDate, MAX_LEN, stdin);
    strtok(currentDate, "\n");
    char date1[MAX_COUNT][MAX_WORD + 1];
    size_t len;
    char temp[MAX_LEN];
    strncpy(temp, currentDate, MAX_LEN);
    int res = split(temp, date1, &len);
    if (res != EXIT_SUCCESS)
    {
        return EXIT_FAILURE;
    }
    if (check_full_date(date1) != EXIT_SUCCESS)
    {
        printf("Неверная дата.\n");
        return EXIT_FAILURE;
    }
    printf("Введите текущее время (ЧЧ:ММ): ");
    fgets(currentTime, MAX_LEN, stdin);
    strtok(currentTime, "\n");
    if (!validateTime(currentTime))
    {
        printf("Неверное время.\n");
        return EXIT_FAILURE;
    }

    size_t i = 0;
    while (i < *count)
    {
        char date2[MAX_COUNT][MAX_WORD + 1];
        res = split(movies[i].date, date2, &len);
        if (res != EXIT_SUCCESS)
        {
            return res;
        }
        if ((compareDates(date1, date2) > DATE_EQUALS) || 
        (compareDates(date1, date2) == DATE_EQUALS && compare_time(currentTime, movies[i].time) > DATE_EQUALS))
        {
            for (size_t j = i; j < *count - 1; j++)
            {
                movies[j] = movies[j + 1];
            }
            (*count)--;
        }
        else
        {
            i++;
        }
    }
    printf("Прошедшие фильмы успешно удалены.\n");
    return EXIT_SUCCESS;
}

void searchByDirectorOrGenre(MovieScreening movies[], size_t count)
{
    char searchTerm[MAX_DIRECTOR_LEN];
    printf("Введите фамилию режиссера или жанр: ");
    fgets(searchTerm, MAX_DIRECTOR_LEN, stdin);
    strtok(searchTerm, "\n");

    int found = 0;
    for (size_t i = 0; i < count; i++)
    {
        if (strstr(movies[i].movie.director, searchTerm) != NULL || strstr(movies[i].movie.genre, searchTerm) != NULL)
        {
            printf("\nНазвание: %s\nЖанр: %s\nРежиссер: %s\nГод: %d\nСтрана: %s\nДлительность: %d\nВозрастное ограничение: %s\nКинотеатр: %s\nДата: %s\nВремя: %s\n",
                   movies[i].movie.title, movies[i].movie.genre, movies[i].movie.director, movies[i].movie.year,
                   movies[i].movie.country, movies[i].movie.duration, movies[i].movie.age_restriction,
                   movies[i].cinema, movies[i].date, movies[i].time);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Не найдено фильмов по режиссеру или жанру\n");
    }
}

void displayMovies(MovieScreening movies[], size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        printf("\nНазвание: %s\nЖанр: %s\nРежиссер: %s\nГод: %d\nСтрана: %s\nДлительность: %d\nВозрастное ограничение: %s\nКинотеатр: %s\nДата: %s\nВремя: %s\n",
               movies[i].movie.title, movies[i].movie.genre, movies[i].movie.director, movies[i].movie.year,
               movies[i].movie.country, movies[i].movie.duration, movies[i].movie.age_restriction,
               movies[i].cinema, movies[i].date, movies[i].time);
    }
}

/**
 * @mainpage main.c
 * @author Инякин Роман
 * @brief Приложение для управления афишей кинотеатра
 * @version 0.1
 * @date 2024-06-05
 *
 */

#include <stdio.h>
#include "movie.h"

int main()
{
    MovieScreening movies[MAX_RECORDS];
    size_t count = 0;
    int choice;

    readMovies(movies, &count);
    int res;
    do
    {
        printf("\nАфиша кинотеатра\n");
        printf("1. Добавить фильм\n");
        printf("2. Удалить прошедшие фильмы\n");
        printf("3. Поиск по режиссеру или жанру\n");
        printf("4. Показать все фильмы\n");
        printf("5. Выйти\n");
        printf("Выберите команду (1-5): ");
        scanf("%d", &choice);
        getchar(); 

        if (choice < 1 || choice > 5)
        {
            printf("Неверная комманда. Введите номер от 1 до 5!\n");
            continue;
        }

        switch (choice)
        {
        case 1:
            res = addMovie(movies, &count);
            if (res == EXIT_SUCCESS)
            {
                saveMovies(movies, count);
            }
            break;
        case 2:
            deletePassedMovies(movies, &count);
            if (res == EXIT_SUCCESS)
            {
                saveMovies(movies, count);
            }
            break;
        case 3:
            searchByDirectorOrGenre(movies, count);
            break;
        case 4:
            displayMovies(movies, count);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Неизвестная команда! Пожалуйста, повторите выбор\n");
            break;
        }
    } while (choice != 5);

    return 0;
}

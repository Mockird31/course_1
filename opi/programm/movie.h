/**
 * @file movie.h
 * @author Инякин Роман
 * @brief Объявление функций для работы с афишей кинотеатра
 * @version 0.1
 * @date 2024-06-05
 * 
 */

#ifndef MOVIE_H
#define MOVIE_H

#include "check_date.h"
#include "validate.h"

#define MAX_TITLE_LEN 100
#define MAX_DIRECTOR_LEN 100
#define MAX_COUNTRY_LEN 50
#define MAX_CINEMA_NAME_LEN 100
#define MAX_GENRE_LEN 20
#define MAX_RECORDS 100
#define MAX_GENRES 5
#define MAX_LEN 256
#define FILE_NAME "movies.txt"

/**
 * @struct MovieInfo
 * @brief Структура данных для хранения информации о фильме.
 *
 * Эта структура содержит поля для хранения различных атрибутов фильма,
 * таких как название (@a title), жанр (@a genre), режиссер (@a director),
 * год выпуска (@a year), страна производства (@a country), продолжительность
 * (@a duration) и возрастное ограничение (@a age_restriction).
 */
typedef struct {
    /**
     * @brief Название фильма.
     */
    char title[MAX_LEN];

    /**
     * @brief Жанр фильма.
     */
    char genre[MAX_LEN];

    /**
     * @brief Режиссер фильма.
     */
    char director[MAX_LEN];

    /**
     * @brief Год выпуска фильма.
     */
    int year;

    /**
     * @brief Страна производства фильма.
     */
    char country[MAX_LEN];

    /**
     * @brief Продолжительность фильма в минутах.
     */
    int duration;

    /**
     * @brief Возрастное ограничение фильма.
     */
    char age_restriction[MAX_LEN];
} MovieInfo;


/**
 * @struct MovieScreening
 * @brief Структура данных для хранения информации о просмотре фильма в кинотеатре.
 *
 * Эта структура содержит информацию о конкретном показе фильма в кинотеатре,
 * включая данные о самом фильме через вложенную структуру @ref MovieInfo,
 * а также информацию о кинотеатре (@a cinema), дате (@a date) и времени (@a time)
 * показа.
 */
typedef struct {
    /**
     * @brief Информация о фильме, показываемом во время данного сеанса.
     */
    MovieInfo movie;

    /**
     * @brief Название кинотеатра, где проходит показ.
     */
    char cinema[MAX_LEN];

    /**
     * @brief Дата показа фильма в формате YYYY-MM-DD.
     */
    char date[MAX_LEN];

    /**
     * @brief Время начала показа фильма в формате HH:MM.
     */
    char time[MAX_LEN];
} MovieScreening;


/*! 
 * @brief Читает информацию о сеансах кино из файла и заполняет массив структур MovieScreening.
 *
 * Функция открывает файл с именем, указанным в макросе FILE_NAME, для чтения. Если файл не может быть открыт,
 * выводится сообщение об ошибке и функция возвращает код ошибки EXIT_FAILURE. В противном случае, функция читает
 * данные о каждом сеансе кино из файла и заполняет массив структур MovieScreening. Каждая структура содержит информацию
 * о фильме и его показе. После успешного чтения всех данных из файла, функция закрывает файл и возвращает код успеха
 * EXIT_SUCCESS.
 *
 * @param[out] movies Массив структур MovieScreening, который будет заполнен данными о сеансах кино.
 * @param[in,out] count Указатель на переменную типа size_t, которая будет увеличена на количество успешно прочитанных записей.
 *                       Изначальное значение должно быть равно нулю.
 *
 * @return Код возврата функции:
 *         - EXIT_SUCCESS, если все операции выполнены успешно.
 *         - EXIT_FAILURE, если произошла ошибка при открытии файла.
 */
int readMovies(MovieScreening movies[], size_t *count);

/**
 * @brief Сохраняет информацию о сеансах кино в файл.
 *
 * Функция принимает массив структур MovieScreening и количество элементов в этом массиве.
 * Каждый элемент массива содержит информацию о фильме и его показе в кинотеатре.
 *
 * @param movies Массив структур MovieScreening, содержащий информацию о сеансах кино.
 * @param count Количество элементов в массиве movies.
 *
 * @return Возвращает EXIT_SUCCESS при успешном выполнении операции или EXIT_FAILURE в случае ошибки открытия файла.
 */
int saveMovies(MovieScreening movies[], size_t count);

/**
 * @brief Добавляет информацию о новом киносеансе в массив сеансов.
 *
 * Функция запрашивает у пользователя ввод информации о фильме и проверяет корректность введенных данных.
 * Если все данные верны, информация сохраняется в массиве, и счетчик записей увеличивается на один.
 * В случае ошибки валидации или превышения максимального количества записей, функция выводит сообщение об ошибке и завершается с кодом ошибки.
 *
 * @param movies Массив структур MovieScreening, содержащий информацию о киносеансах.
 * @param count Указатель на переменную, хранящую количество текущих записей в массиве movies.
 * @return Возвращает EXIT_SUCCESS при успешном добавлении фильма или EXIT_FAILURE в случае ошибки.
 */
int addMovie(MovieScreening movies[], size_t *count);

/**
 * @brief Удаляет из массива показы фильмов, которые уже прошли на момент указанной даты и времени.
 *
 * Функция принимает массив структур MovieScreening, представляющих собой информацию о показах фильмов, а также указатель на количество элементов в этом массиве. Пользователю предлагается ввести текущую дату и время.
 * Затем функция проверяет каждую запись в массиве и удаляет те, которые соответствуют условиям:
 * - Дата показа меньше введенной даты.
 * - Или дата показа равна введенной, но время показа меньше введенного времени.
 *
 * После обработки всех записей в массиве, функция выводит сообщение об успешном удалении прошедших показов фильмов.
 *
 * @param movies[] Массив структур MovieScreening, содержащий информацию о показах фильмов.
 * @param count Указатель на переменную, хранящую количество элементов в массиве movies[].
 * @return Возвращает EXIT_SUCCESS, если все прошло успешно, или EXIT_FAILURE в случае ошибок при вводе данных.
 */
int deletePassedMovies(MovieScreening movies[], size_t *count);

/**
 * @brief Поиск сеансов кино по режиссёру или жанру
 *
 * Функция позволяет пользователю ввести фамилию режиссёра или название жанра и выводит информацию о всех сеансах кино, которые соответствуют введённому критерию поиска. Если ни один из сеансов не соответствует критериям, выводится сообщение об отсутствии результатов.
 *
 * @param movies Массив структур MovieScreening, содержащий информацию о сеансах кино
 * @param count Количество элементов в массиве movies
 */
void searchByDirectorOrGenre(MovieScreening movies[], size_t count);

/**
 * @brief Отображает информацию о сеансах фильмов в консоли.
 *
 * Функция проходит по массиву сеансов фильмов и выводит детали каждого сеанса: название фильма, жанр, режиссёр, год выпуска, страна производства, длительность, возрастное ограничение, кинотеатр, дату и время показа.
 *
 * @param movies Массив структур MovieScreening, содержащий информацию о сеансах фильмов.
 * @param count Количество элементов в массиве movies.
 */
void displayMovies(MovieScreening movies[], size_t count);

#endif

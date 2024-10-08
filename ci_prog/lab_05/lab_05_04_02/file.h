#ifndef _FILE_H_
#define _FILE_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "product.h"
#include <inttypes.h>

#define MAX_LINE 70
#define MAX_PRODUCTS 100

#define FILE_NOT_DEFINED 2
#define ERROR_SIZE 3
#define ERROR_EMPTY 4
#define ERROR_DATA 5
#define ERROR_ARGS 53
#define ERROR_INPUT 6

/**
 * @brief Функция для подсчета количества строк в файле и определения длины данных.
 *
 * @param file Указатель на открытый файл, который нужно обработать.
 * @param len Указатель на переменную типа size_t, которая будет содержать результат подсчета.
 * @return В случае успешного выполнения возвращает EXIT_SUCCESS, в противном случае - ERROR_EMPTY.
 */
int get_len(FILE *file, size_t *len);

/**
 * @brief Функция для чтения информации о продуктах из файла.
 *
 * @param path Путь к файлу с информацией о продуктах.
 * @param[out] products Массив для хранения прочитанных продуктов.
 * @param[out] len Указатель на переменную, в которую будет записано количество прочитанных продуктов.
 * @return Возвращает код ошибки или EXIT_SUCCESS в случае успешного выполнения.
 */
size_t read_products(char *path, product_t products[], size_t *len);

/**
 * @brief Записывает информацию о продуктах в файл.
 *
 * @param path Путь к файлу, в который будут записаны данные о продуктах.
 * @param products Массив структур типа product_t, содержащий информацию о продуктах.
 * @param len Количество элементов в массиве products.
 * @return EXIT_SUCCESS при успешной записи данных или FILE_NOT_DEFINED в случае ошибки открытия файла.
 */
int write_products(char *path, product_t products[], size_t len);

/**
 * @brief Сортирует массив продуктов по цене и количеству.
 *
 * Функция сортирует переданный массив продуктов так, чтобы продукты с более низкой ценой шли первыми.
 * Если цены равны, то сортировка производится по убыванию количества товара.
 *
 * @param products Массив продуктов для сортировки.
 * @param len Количество элементов в массиве products.
 */
void compare_by_price(product_t products[], size_t len);

/**
 * @brief Сортировка продуктов по цене и запись в файл назначения.
 *
 * @param path_src Путь к исходному файлу с продуктами.
 * @param path_dst Путь к целевому файлу, куда будут записаны отсортированные продукты.
 * @return Возвращает код завершения операции:
 *         - EXIT_SUCCESS, если все операции выполнены успешно.
 *         - Код ошибки, если произошла ошибка при чтении или записи файлов.
 */
int sorting(char *path_src, char *path_dst);

/**
 * @brief Функция выводит информацию о продуктах, чьи названия оканчиваются заданной подстрокой.
 *
 * @param path Путь к файлу, который будет открыт для чтения.
 * @param substr Подстрока, которой должно оканчиваться название продукта.
 * @param products Массив структур, содержащих информацию о продуктах.
 * @param len Количество элементов в массиве продуктов.
 *
 * @return Возвращает код ошибки или успеха выполнения операции:
 *         - ERROR_ARGS, если подстрока пуста.
 *         - FILE_NOT_DEFINED, если файл не удалось открыть.
 *         - ERROR_EMPTY, если ни один продукт не соответствует критерию.
 *         - EXIT_SUCCESS, если все прошло успешно.
 */
int print_prep_data(char *path, char *substr, product_t products[], size_t len);

/**
 * @brief Функция выводит информацию о продуктах, удовлетворяющих заданному условию в конце строки.
 *
 * @param path Путь к файлу с данными о продуктах.
 * @param substr Подстрока, которую нужно найти в конце названий продуктов.
 * @return Возвращает код завершения операции:
 *         - EXIT_SUCCESS, если все операции выполнены успешно.
 *         - Код ошибки, если произошла ошибка при чтении данных или печати информации.
 */
int print_endstr(char *path, char *substr);

/**
 * @brief Получение информации о продукте из файла
 *
 * @param prod Указатель на структуру product_t, которая будет заполнена информацией о продукте.
 * @param file Указатель на файл, из которого будет считана информация.
 * @return Возвращает код ошибки или успеха выполнения операции:
 *         - EXIT_SUCCESS если все данные успешно прочитаны,
 *         - ERROR_INPUT если произошла ошибка при чтении данных,
 *         - EXIT_FAILURE если произошла неожиданная ошибка ввода-вывода.
 */
int get_info_about_prod(product_t *prod);

/**
 * @brief Вставляет продукт в файл в отсортированном порядке по цене и количеству.
 *
 * @param path Путь к файлу, в который будет добавлен продукт.
 * @return Код возврата:
 *         - EXIT_SUCCESS, если операция выполнена успешно.
 *         - ERROR_DATA, если произошла ошибка при записи данных в файл.
 */
int insert_in_file(char *path);

#endif
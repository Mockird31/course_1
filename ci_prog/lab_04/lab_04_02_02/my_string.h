#ifndef _MY_STRING_H_
#define _MY_STRING_H_

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "codeOut.h"
#define MAX_STR 256
#define MAX_WORD 16
#define MAX_COUNT 128
#define SEPS " ,;:-.!?\n"

/**
 * @brief Функция для ввода строки от пользователя.
 *
 * @param str Указатель на буфер, куда будет скопирована строка.
 *
 * @return int Возвращает код успеха (SUCCESS) или код ошибки ввода (INPUT_ERROR), если ввод не соответствует требованиям.
 */
int input_strings(char *str);

/**
 * @brief Разделяет строку на слова, используя предопределенные разделители.
 *
 * @param str Строка, которую нужно разделить на слова.
 * @param words Массив для хранения слов. Каждое слово должно быть меньше или равно
 *              MAX_WORD символов, а общее количество слов не должно превышать MAX_COUNT.
 * @param len Указатель на переменную, в которой будет сохранено количество найденных слов.
 *
 * @return SUCCESS в случае успешного выполнения, иначе код ошибки.
 */
int split(char *str, char words[MAX_COUNT][MAX_WORD + 1], size_t *len);

/**
 * @brief Проверяет, содержатся ли слова из первого массива в другом массиве.
 *
 * @param words1 Первый массив слов, размер которого определяется параметром len1.
 * @param words2 Второй массив слов, размер которого определяется параметром len2.
 * @param len1 Количество слов в первом массиве.
 * @param len2 Количество слов во втором массиве.
 * @return int Возвращает NO_WORDS, если один из массивов пуст, и SUCCESS в противном случае.
 */
int in_other(char words1[MAX_COUNT][MAX_WORD + 1], char words2[MAX_COUNT][MAX_WORD + 1], size_t len1, size_t len2);

/**
 * @brief Проверяет, содержится ли заданное слово в массиве слов.
 *
 * @param word Слово, которое нужно проверить на наличие в массиве.
 * @param new_words Двумерный массив символов, представляющий массив слов.
 * @param len Количество слов в массиве new_words.
 *
 * @return int 1, если слово найдено, иначе 0.
 */
int is_word_in_array(char *word, char new_words[MAX_COUNT][MAX_WORD + 1], size_t len);

/**
 * @brief Создает массив уникальных слов из исходного массива.
 *
 * @param words Исходный массив слов, из которого нужно создать уникальные слова.
 * @param len Длина исходного массива слов.
 * @param new_words Массив, в который будут добавлены уникальные слова.
 * @param new_len Указатель на переменную, в которую будет записана длина нового массива после выполнения функции.
 */
void make_unique(char words[MAX_COUNT][MAX_WORD + 1], size_t len, char new_words[MAX_COUNT][MAX_WORD + 1], size_t *new_len);

#endif

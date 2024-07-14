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
 * @brief Функция для ввода строки с проверкой на ошибки.
 *
 * @param str Указатель на буфер, куда будет скопирована введенная строка.
 * @return int Возвращает SUCCESS в случае успешного ввода, INPUT_ERROR в случае ошибки ввода.
 */
int input_strings(char *str);

/**
 * @brief Разделяет строку на слова, используя заданные разделители.
 *
 * @param str Строка, которую нужно разделить на слова.
 * @param words Двумерный массив, в который будут сохранены разделенные слова.
 * @param len Указатель на переменную, в которую будет записан количество разделенных слов.
 *
 * @return SUCCESS в случае успешного выполнения, иначе код ошибки.
 */
int split(char *str, char words[MAX_COUNT][MAX_WORD + 1], size_t *len);

/**
 * @brief Объединяет слова из массива в одну строку, удаляя первый символ каждого слова.
 * 
 * @param res Указатель на строку, в которую будет записано объединенное слово.
 * @param words Двумерный массив символов, представляющий слова для объединения.
 * @param len Количество слов в массиве words.
 */
int join(char *res, char words[MAX_COUNT][MAX_WORD + 1], int len);

/**
 * @brief Удаляет первое вхождение символа из строки и копирует результат в новую строку.
 *
 * @param word Указатель на исходную строку, из которой нужно удалить символ.
 * @param new_word Указатель на строку, в которую будет скопирован результат.
 */
void del_first_symb(char *word, char *new_word);

/**
 * @brief Создает уникальные слова из массива слов, удаляя дубликаты.
 *
 * @param words Массив исходных слов, размер которого определяется MAX_COUNT и MAX_WORD.
 * @param len Длина исходного массива слов.
 * @param new_words Массив, в который будут записаны уникальные слова.
 * @param new_len Указатель на переменную, в которую будет записана длина нового массива слов.
 */
void make_unique(char words[MAX_COUNT][MAX_WORD + 1], size_t len, char new_words[MAX_COUNT][MAX_WORD + 1], size_t *new_len);

#endif

#ifndef _MY_STRING_H_
#define _MY_STRING_H_

#include <stdio.h>
#include "codeOut.h"

#define MAX_STR 256
#define MAX_WORD 16

/**
 * @brief Находит первое вхождение любого символа из второго строки в первую строку.
 *
 * @param str1 Строка, в которой производится поиск.
 * @param str2 Строка, содержащая символы для поиска.
 * @return Указатель на первый найденный символ из `str2` в `str1`, или NULL, если символ не найден.
 */
char *my_strpbrk(const char *str1, const char *str2);

/**
 * @brief Возвращает длину наибольшей подстроки str1, которая состоит только из символов, присутствующих в str2.
 *
 * @param str1 Строка, из которой ищется подстрока.
 * @param str2 Строка, содержащая символы для поиска.
 * @return size_t Длина наибольшей подстроки str1, состоящей только из символов из str2.
 */
size_t my_strspn(const char *string1, const char *string2);

/**
 * @brief Находит первое вхождение любого символа из str2 в str1.
 *
 * @param str1 Строка, в которой производится поиск.
 * @param str2 Строка, содержащая символы для поиска.
 * @return Позиция первого вхождения символа из str2 в str1, или длина str1, если такого символа нет.
 */
size_t my_strcspn(const char *string1, const char *string2);

/**
 * @brief Поиск первого вхождения символа в строке.
 *
 * @param str Строка, в которой производится поиск.
 * @param symbol Символ, который нужно найти.
 * @return Указатель на первое вхождение символа в строке, NULL если символ не найден.
 *         Если искомый символ - это нулевой символ, возвращает указатель на конец строки.
 */
char *my_strchr(const char *str, int symbol);

/**
 * @brief Поиск последнего вхождения символа в строке.
 *
 * @param str Строка, в которой производится поиск.
 * @param symbol Символ, который нужно найти.
 * @return Указатель на найденный символ в строке или NULL, если символ не найден.
 *
 */
char *my_strrchr(const char *str, int symbol);
#endif

#ifndef _FILE_H_
#define _FILE_H_

#include <stdio.h>
#include <stdlib.h>

#define NOT_ENOUGH_ELEMS 2
#define INT_MIN -2147483647 - 1

/**
 * @brief Обработка файла для поиска индекса максимального элемента последовательности чисел.
 *
 * @param f Указатель на открытый файл, содержащий последовательность целых чисел.
 * @param max_index Указатель на переменную, которая будет содержать индекс максимального элемента.
 *                  Индексация начинается с 1. Если функция возвращает NOT_ENOUGH_ELEMS,
 *                  значение *max_index не определено.
 * @return В случае успешной обработки файла возвращает EXIT_SUCCESS.
 *         Если в файле недостаточно элементов для сравнения, возвращает NOT_ENOUGH_ELEMS.
 */
int process(FILE *f, size_t *max_index);

#endif
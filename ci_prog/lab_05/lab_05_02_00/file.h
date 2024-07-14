#ifndef _FILE_H_
#define _FILE_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define FILE_NOT_DEFINE 2
#define NOT_NUMBER 3
#define EMPTY_ERROR 4
#define IS_END 5
#define DBL_MAX 100000

/**
 * @brief Вычисляет среднее значение чисел из файла.
 *
 * @param f Указатель на файл, из которого будут считываться числа.
 * @param aver Указатель на переменную, в которой будет сохранено среднее значение.
 * @return Код завершения операции. В случае успешного выполнения возвращает EXIT_SUCCESS.
 */
int find_average(FILE *f, double *aver);

/**
 * @brief Находит ближайшее число к заданному среднему значению в файле.
 *
 * @param f Указатель на открытый файл, содержащий числа для анализа.
 * @param aver Среднее значение, к которому нужно найти ближайшее число.
 * @return Ближайшее к среднему значению число из файла.
 */
double find_closest(FILE *f, double aver);

#endif
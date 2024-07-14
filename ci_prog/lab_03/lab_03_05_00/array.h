#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <stdio.h>

/**
 * @brief Appends an element to the end of an array.
 *
 * This function adds an element to the end of an array by placing it at the index
 * specified by the current length of the array. It then increments the length of
 * the array to reflect the addition of the new element.
 *
 * @param arr Pointer to the array where the element will be added.
 * @param len Pointer to the size variable of the array. This will be incremented
 *            after the element is added.
 * @param el The element to be added to the end of the array.
 *
 * @note This function assumes that the array has enough allocated space to hold
 *       the new element. It does not perform any bounds checking.
 */
void append(int *arr, size_t *len, int el);

/**
 * @brief Reverses an array in place.
 *
 * This function takes an array and its size as input and reverses the order of elements in the array.
 * It uses a two-pointer technique to swap elements from the start and end of the array, moving towards the center.
 *
 * @param arr Pointer to the array to be reversed.
 * @param len The number of elements in the array.
 */
void reverse(int *arr, size_t len);
#endif
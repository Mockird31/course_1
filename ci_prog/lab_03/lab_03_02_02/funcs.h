#ifndef _FUNCS_H_
#define _FUNCS_H_

#include "codeOut.h"
#define DELIT 10
/**
 * @brief Calculates the sum of digits in an integer.
 *
 * This function takes an integer as input, calculates the sum of its digits, and returns the result.
 * If the input number is less than 10, it returns an error code defined by INPUT_ERROR_ELEM.
 *
 * @param n The integer whose digits' sum is to be calculated.
 * @return The sum of the digits of the input integer or INPUT_ERROR_ELEM if the input is less than 10.
 */
int sum_cif(int n);

#endif

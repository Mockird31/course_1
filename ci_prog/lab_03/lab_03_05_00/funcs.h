#ifndef _FUNCS_H_
#define _FUNCS_H_

#include <stdlib.h>
#include <math.h>
#include "codeOut.h"

/**
 * @brief Checks if a given number is prime.
 *
 * This function determines whether a given integer is a prime number.
 * A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself.
 *
 * @param n The integer to check for primality.
 * @return FAIL_PRIME if the number is not prime, SUCCESS if the number is prime.
 *
 * @note This function uses a simple trial division method to check for primality, which is not the most efficient for large numbers.
 */
int is_prime(int n);

#endif
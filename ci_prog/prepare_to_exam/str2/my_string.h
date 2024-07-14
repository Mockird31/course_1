#ifndef _MY_STRING_H_
#define _MY_STRING_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "code_errors.h"

#define MAX_STR 256
#define MAX_WORD 16
#define SEPS " .,:;"

typedef char words_t[MAX_STR / 2][MAX_WORD];

int input_string(char *str);
int split(char *str, words_t words, size_t *len);
int is_numeric(char *str);
void reverse(char *str);
void join(words_t words, size_t len, char *str);
int reverse_in_arr(words_t words, size_t len);

#endif
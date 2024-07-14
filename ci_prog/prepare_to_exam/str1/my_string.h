#ifndef _MY_STRING_H_
#define _MY_STRING_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#include "error_codes.h"

#define MAX_LEN 256
#define MAX_WORD 16
#define SEPS " .,:;"

int input_string(char *str);
int split(char *str, char words[MAX_LEN][MAX_WORD], size_t *len);
int is_numeric(char *str);
int replace_max_and_min(char words[MAX_LEN][MAX_WORD], size_t len);
int str_to_num(char *str);
int join(char *str, char words[MAX_LEN][MAX_WORD], size_t len);
void swap(char *str1, char *str2);

#endif
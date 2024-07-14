#ifndef _MY_STRING_H_
#define _MY_STRING_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "error_codes.h"

#define MAX_LEN 32
#define SEPS " ,;:-!\t"

int input_string(char *str);
int split(char *str, char words[MAX_LEN][MAX_LEN], size_t *len);
void reverse(char *word);
int join(char words[MAX_LEN][MAX_LEN], size_t len, char *str);

#endif
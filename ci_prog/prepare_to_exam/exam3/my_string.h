#ifndef _MY_STRING_H
#define _MY_STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "error_code.h"
#define MAX_LEN 32
#define SEPS " \t"

int input_string(char *str);
int count_num(char *str, int *sum);
int is_number(char *str);
int str_to_num(char *word);

#endif
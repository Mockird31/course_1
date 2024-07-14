#ifndef _FILE_H_
#define _FILE_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define FILE_NOT_DEFINE 2
#define MAX_STR 16
#define INVALIV_NUM_OF_ARG 3
#define ERROR_SIZE 4
#define ERROR_EMPTY 5
#define MAX_SIZE 20
#define ERROR_ARGS 6

int get_number_by_pos(FILE *f, size_t pos, int *find_num);

int put_number_by_pos(FILE *f, size_t pos, int num);

int generate_file(char *path, size_t len);

int print_file(char *path, size_t len);

int main_func(char *path, size_t *len);

int get_size_bin(char *path, size_t *len);

#endif
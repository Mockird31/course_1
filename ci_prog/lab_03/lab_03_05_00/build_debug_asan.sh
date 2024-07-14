#!/bin/bash

gcc -std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -fsanitize=address -fno-omit-frame-pointer -g -c main.c matrix.c funcs.c array.c
gcc -fsanitize=address -g main.o matrix.o funcs.o array.o -o app.exe -lm
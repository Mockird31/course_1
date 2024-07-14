#!/bin/bash

gcc -std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -fsanitize=undefined -fno-omit-frame-pointer -g -c main.c matrix.c funcs.c
gcc -fsanitize=undefined -g main.o matrix.o funcs.o -o app.exe -lm

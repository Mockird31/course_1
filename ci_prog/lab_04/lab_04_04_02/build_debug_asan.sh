#!/bin/bash

gcc -std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -fsanitize=address -fno-omit-frame-pointer -g -c main.c my_string.c
gcc -fsanitize=address -g main.o my_string.o -o app.exe -lm
#!/bin/bash

gcc -std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -fsanitize=address -fno-omit-frame-pointer -g -c main.c matrix.c
gcc -fsanitize=address -g main.o matrix.o -o app.exe -lm
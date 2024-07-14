#!/bin/bash

clang -std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -fsanitize=undefined -fno-omit-frame-pointer -g -c -o main.o main.c
clang -fsanitize=undefined -g main.o -o app.exe -lm

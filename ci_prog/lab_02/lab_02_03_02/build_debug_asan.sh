#!/bin/bash

clang -std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -fsanitize=address -fno-omit-frame-pointer -g -c -o main.o main.c
clang -fsanitize=address -g main.o -o app.exe -lm
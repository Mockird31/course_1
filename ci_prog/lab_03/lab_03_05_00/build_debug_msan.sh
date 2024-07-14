#!/bin/bash

gcc -std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -fsanitize=memory -fPIE -fno-omit-frame-pointer -g -c main.c matrix.c funcs.c array.c
gcc -fsanitize=memory -pie -g main.o matrix.o funcs.o array.o -o app.exe -lm

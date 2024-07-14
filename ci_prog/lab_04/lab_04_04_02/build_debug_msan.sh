#!/bin/bash

gcc -std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -fsanitize=memory -fPIE -fno-omit-frame-pointer -g -c main.c my_string.c
gcc -fsanitize=memory -pie -g main.o my_string.o -o app.exe -lm

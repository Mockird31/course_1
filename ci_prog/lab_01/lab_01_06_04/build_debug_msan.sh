#!/bin/bash

clang -std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -fsanitize=memory -fPIE -fno-omit-frame-pointer -g -c -o main.o main.c 
clang -fsanitize=memory -pie -g main.o -o app.exe -lm

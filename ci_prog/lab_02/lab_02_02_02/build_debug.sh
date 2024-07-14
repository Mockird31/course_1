#!/bin/bash

gcc-13 -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -c -O0 -g3 main.c -o main.o -lm
gcc-13 -std=c99 -g main.o -o app.exe 
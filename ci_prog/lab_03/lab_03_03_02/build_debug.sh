#!/bin/bash

gcc-13 -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -c -O0 -g3 main.c matrix.c -lm
gcc-13 -std=c99 -g main.o matrix.o -o app.exe 
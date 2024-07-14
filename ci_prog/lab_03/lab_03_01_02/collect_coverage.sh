#!/bin/bash

gcc-13 -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -c -O0 -g3 --coverage main.c matrix.c array.c -lm
gcc-13 main.o matrix.o array.o -o app.exe --coverage

./func_tests/scripts/func_tests.sh
gcov-13 main.c matrix.c array.c
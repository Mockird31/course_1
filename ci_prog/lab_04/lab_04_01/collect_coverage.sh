#!/bin/bash

gcc-13 -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -c -O0 -g3 --coverage main.c my_string.c -lm
gcc-13 main.o my_string.o -o app.exe --coverage

./func_tests/scripts/func_tests.sh
gcov-13 main.c my_string.c
#!/bin/bash

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -c -O0 -g3 --coverage main.c -lm
gcc main.o -o app.exe --coverage

./func_tests/scripts/func_tests.sh
gcov main.c

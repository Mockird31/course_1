#!/bin/bash

gcc -c -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -o main.o main.c -lm
gcc -std=c99 -o app.exe main.o 
#!/bin/bash

gcc-13 -c -std=c99 -Wall -Werror -Wvla -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -o main.o main.c -lm
gcc-13 -std=c99 -o app.exe main.o 
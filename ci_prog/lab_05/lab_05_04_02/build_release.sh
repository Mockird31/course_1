#!/bin/bash

gcc-13 -c -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla main.c file.c -lm
gcc-13 -std=c99 -o app.exe main.o file.o
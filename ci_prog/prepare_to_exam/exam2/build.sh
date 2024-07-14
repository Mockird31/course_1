#!/bin/bash

gcc-13 -c -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla main.c product.c -lm
gcc-13 -std=c99 -o app.exe main.o product.o

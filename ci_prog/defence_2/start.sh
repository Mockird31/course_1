#!/bin/bash

gcc-13 -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -Wvla -o app.exe main.c
./app.exe

#!/bin/bash

files="/./func_tests/scripts/ *.txt *.exe *.o *.gcno *.gcda *.gcov"

for file in $files; do
    rm -f "$file"
done
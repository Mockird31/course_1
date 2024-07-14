#!/bin/bash

dir="./exe_files/"
if ! [[ -d "$dir" ]]; then 
    mkdir exe_files
fi

gcc-13 -std=c99 -Wall -Werror -Wextra -Wpedantic -O0 -c funcs.c -o ./exe_files/funcs.o

names=$(sed -n "1p" config.txt)
sizes=$(sed -n "2p" config.txt)

for name in $names; do
    for size in $sizes; do
        gcc-13 -std=c99 -Wall -Werror -Wpedantic -Wextra -DLEN="$size" -c -O0 "$name".c -o ./exe_files/"$name"_"$size".o -lm
        gcc-13 ./exe_files/"$name"_"$size".o ./exe_files/funcs.o -o ./exe_files/"$name"_"$size".exe
        rm ./exe_files/"$name"_"$size".o
    done
done

rm ./exe_files/funcs.o
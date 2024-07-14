#!/bin/bash

if ! [[ -f $1 ]] || ! [[ -f $2 ]]; then
    echo -e "\033[31m\033[1mFile not exist\033[0m"
fi

if [[ $# != 2 ]]; then
    echo -e "\033[31m\033[1mNot enough arguments\033[0m"
fi

file1=$1
file2=$2

regex="[+-]?[0-9]+(\.[0-9]+)?"

file1_res=$(grep -Eo "$regex" "$file1")

file2_res=$(grep -Eo "$regex" "$file2")

if [[ "$file1_res" == "$file2_res" ]]; then
    exit 0
else 
    exit 1
fi



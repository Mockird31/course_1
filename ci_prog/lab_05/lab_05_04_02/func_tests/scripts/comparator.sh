#!/bin/bash

if ! [[ -f $1 ]] || ! [[ -f $2 ]]; then
    echo -e "\033[31m\033[1mFile not exist\033[0m"
fi

if [[ $# != 2 ]]; then
    echo -e "\033[31m\033[1mNot enough arguments\033[0m"
fi

file1_res=$(cat $1)
file2_res=$(cat $2)

if [[ "$file1_res" == "$file2_res" ]]; then
    exit 0
else 
    exit 1
fi


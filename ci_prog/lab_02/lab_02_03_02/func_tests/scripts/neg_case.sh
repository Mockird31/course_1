#!/bin/bash

if [[ $# != 1 ]]; then
    exit 1
fi 

if ! [[ -e "./app.exe" ]]; then 
    $"./build_release.sh"
fi

neg_in=$1
app="./app.exe"
output="output.txt"

$app < "$neg_in" > "$output"
res="$?"

if [[ "$res" == 0 ]]; then 
    exit 1
else 
    exit 0
fi


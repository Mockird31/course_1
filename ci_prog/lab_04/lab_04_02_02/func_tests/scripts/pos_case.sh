#!/bin/bash

if [ $# != 2 ]; then
    exit 1
fi

if ! [[ -e "./app.exe" ]]; then 
    $"./build_release.sh"
fi

pos_in=$1
pos_out=$2

app="./app.exe"

output="output.txt"

$app < "$pos_in" > "$output"
res1="$?"

if [ "$res1" != 0 ]; then
    exit 1
fi

com="./func_tests/scripts/comparator.sh ""$pos_out"" $output"
$com 
res="$?"

if [[ "$res" == 0 ]]; then
    exit 0
else
    exit 1
fi

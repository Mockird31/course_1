#!/bin/bash

if [ $# != 2 ]; then
    exit 1
fi

if ! [[ -e "./app.exe" ]]; then 
    $"./build_release.sh"
fi

pos_in=$1
pos_out=$2

output="output.txt"

args=$(cat "$pos_in")
./app.exe "$args"> "$output"

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

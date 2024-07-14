#!/bin/bash

if [ $# != 3 ]; then
    exit 1
fi

if ! [[ -e "./app.exe" ]]; then 
    $"./build_release.sh"
fi

pos_in=$1
pos_out=$2
args_file=$3

output="output.txt"
output_conv="output_conv.txt"

i=0
for word in $(cat "$args_file"); do 
    words[i]="$word"
    (( i+=1 ))
done

if [[ "$i" -lt 3 ]]; then
    exit 1
fi

if [[ "${words[$(( i - 1 ))]}" == *.txt ]]; then
    ./app.exe "${words[@]}"
    res1="$?"
else 
    ./app.exe "${words[@]}" > "$output_conv"
    res1="$?"
fi

if [ "$res1" != 0 ]; then
    exit 1
fi

if [[ "${words[$(( i - 1 ))]}" == *.txt ]]; then
    com="./func_tests/scripts/comparator.sh ""$pos_out"" $output"
else
    com="./func_tests/scripts/comparator.sh ""$pos_out"" $output_conv"
fi

$com 
res="$?"

if [[ "$res" == 0 ]]; then
    exit 0
else
    exit 1
fi

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
in_bin="in.bin"
./app.exe import "$pos_in" "$in_bin"
args=$(cat "$args_file")

i=0
for word in $(cat "$args_file"); do 
    words[i]="$word"
    (( i+=1 ))
done

./app.exe "${words[@]}" > "$output"
res1="$?"
./app.exe export "$in_bin" "$output"

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

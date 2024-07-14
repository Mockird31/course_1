#!/bin/bash

if [[ $# != 2 ]]; then
    exit 1
fi 

if ! [[ -e "./app.exe" ]]; then 
    $"./build_release.sh"
fi

in_file=$1
args_file=$2
output="output.txt"
i=0
for word in $(cat "$args_file"); do 
    words[i]="$word"
    (( i+=1 ))
done

if [[ "${words[$(( i - 1 ))]}" == *.txt ]]; then
    ./app.exe "${words[@]}"
    res="$?"
else 
    ./app.exe "${words[@]}" > "$output"
    res="$?"
fi

if [[ "$res" == 0 ]]; then 
    exit 1
else 
    exit 0
fi


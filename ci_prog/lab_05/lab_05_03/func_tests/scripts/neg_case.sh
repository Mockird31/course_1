#!/bin/bash

if [[ $# != 2 ]]; then
    exit 1
fi 

if ! [[ -e "./app.exe" ]]; then 
    $"./build_release.sh"
fi

in_file=$1
args_file=$2
in_bin="in.bin"
./app.exe import "$pos_in" "$in_bin"
args=$(cat "$args_file")

i=0
for word in $(cat "$args_file"); do 
    words[i]="$word"
    (( i+=1 ))
done

./app.exe "${words[@]}" 
res="$?"

if [[ "$res" == 0 ]]; then 
    exit 1
else 
    exit 0
fi

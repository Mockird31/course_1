#!/bin/bash

if [[ $# != 1 ]]; then
    exit 1
fi 

if ! [[ -e "./app.exe" ]]; then 
    $"./build_release.sh"
fi

in_file=$1
args=$(cat "$in_file")

./app.exe "$args"

res="$?"

if [[ "$res" == 0 ]]; then 
    exit 1
else 
    exit 0
fi


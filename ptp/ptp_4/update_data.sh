#!/bin/bash

if [[ -z $1 ]]; then
    echo -e "\033[91m\033[1mОшибка! Неведено сколько раз необходимо сделать замер!\033[0m"
    exit 1
fi

count=$1

if ! [[ -e "./exe_files" ]]; then
    echo -e "\033[91m\033[1mОшибка! Отсутсвует каталог с исполняемыми файлами!\033[0m"
    exit 2
fi

dir="./data_set/"
if ! [[ -d "$dir" ]]; then 
    mkdir data_set
fi

names=$(sed -n "1p" config.txt)
sizes=$(sed -n "2p" config.txt)


for name in $names; do
    for size in $sizes; do
        ./exe_files/"$name"_"$size".exe &> /dev/null
    done
done


for _ in $(seq "$count"); do
    for name in $names; do
        for size in $sizes; do
            ./exe_files/"$name"_"$size".exe >>./data_set/"$name"_"$size".txt
        done
    done
done


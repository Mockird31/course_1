#!/bin/bash

#цвета вывода
RED="\033[31m\033[1m"
GREEN="\033[32m\033[1m"
END="\033[0m"

files_pos="./func_tests/data/pos_??_args.txt"
files_neg="./func_tests/data/neg_??_args.txt"
regex="[0-9][0-9]"

#число проваленных тестов
pos_count=0
neg_count=0

#число тестов
amount_pos=false
amount_neg=false

#позитивные тесты
for in_file in $files_pos; do
    number=$(echo "$in_file" | grep -o "$regex")
    if [[ -e "$in_file" ]]; then
        (( amount_pos++ ))
    else 
        break
    fi

    out_file="./func_tests/data/pos_$number""_out.txt"

    pos_t="./func_tests/scripts/pos_case.sh ""$in_file ""$out_file "

    $pos_t
    res="$?"

    if [[ "$res" == 0 ]]; then 
        echo -e "$GREEN""POS_""$number"" PASS""$END"
    else 
        echo -e "$RED""POS_""$number"" FAIL""$END"
        (( pos_count++ ))
    fi
done

if ! [[ amount_pos -eq 0 ]]; then
    if ! [[ pos_count -eq 0 ]]; then
        echo -e "$RED""Failed positive tests: $pos_count""$END"
    else 
        echo -e "$GREEN""All positive tests was passed""$END"
    fi
else 
    echo -e "\033[1mNo positive tests\033[0m"
fi

#негативные тесты
for in_file in $files_neg; do
    number=$(echo "$in_file" | grep -o "$regex")

    if [[ -e "$in_file" ]]; then 
        (( amount_neg++ ))
    else 
        break
    fi

    neg_t="./func_tests/scripts/neg_case.sh ""$in_file "

    $neg_t
    res="$?"

    if [[ "$res" == 0 ]]; then 
        echo -e "$GREEN""NEG_""$number"" PASS""$END"
    else 
        echo -e "$RED""NEG_""$number"" FAIL""$END"
        (( neg_count++ ))
    fi
done

if ! [[ amount_neg -eq 0 ]]; then 
    if ! [[ neg_count -eq 0 ]]; then
        echo -e "$RED""Failed negative tests: $neg_count""$END"
    else 
        echo -e "$GREEN""All negative tests was passed""$END"
    fi
else 
    echo -e "\033[1mNo negative tests\033[0m"
fi

fail_tests=$(( pos_count + neg_count ))

if [[ $fail_tests -eq 0 ]]; then 
    exit 0
else
    exit "$fail_tests"
fi

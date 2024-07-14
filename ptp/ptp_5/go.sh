#!/bin/bash

# 1-ый вопрос
if [[ -f "data1.txt" ]]; then
    rm data1.txt
fi
p1=0$(echo "scale=4; $RANDOM / 32767" | bc)
p2=0$(echo "scale=4; $RANDOM / 32767" | bc)
for _ in $(seq 15); do
    echo "$p1" "$p2" | ./app1.exe >>data1.txt
done
python3 quest_1.py

# 2-ой вопрос
if [[ -f "data2.txt" ]]; then
    rm data2.txt
fi
for _ in $(seq 15); do
    x=0$(echo "scale=4; $RANDOM / 32767" | bc)
    y=0$(echo "scale=4; $RANDOM / 32767" | bc)
    res=$(echo -e "$x\n$y" | ./app1.exe)
    echo "$x" "$y" "$res" >>data2.txt
done
python3 quest_2.py

# 3-й вопрос
if [[ -f "data3.txt" ]]; then
    rm data3.txt
fi
for x in $(seq 10); do
    echo "$((x / 10))" "0.5" | ./app1.exe >>data3.txt
done

for ((x = 10; x >= 1; x--)); do
    echo "$((x / 10))" "0.5" | ./app1.exe >>data3.txt
done
python3 quest_3.py

# 4-ый вопрос
if [[ -f "data4.txt" ]]; then
    rm data4.txt
fi
for _ in $(seq 10); do
    x=0$(echo "scale=4; $RANDOM / 32767" | bc)
    y=0$(echo "scale=4; $RANDOM / 32767" | bc)
    echo "$x" "$y" | ./app1.exe >>data4.txt
done
python3 quest_4.py

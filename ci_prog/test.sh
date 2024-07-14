#!/bin/bash

read pos
read neg 

for (( i=1; i<=pos; i++ )); do
	var1="pos_0"$i"_in.txt"
	var2="pos_0"$i"_out.txt"
	var4="pos_0"$i"_args.txt"
	touch "func_tests/data/$var1"
	touch "func_tests/data/$var2"
	touch "func_tests/data/$var4"
done

for (( i=1; i<=neg; i++ )); do
	var3="neg_0"$i"_in.txt"
	var5="neg_0"$i"_args.txt"
	touch "func_tests/data/$var3"
	touch "func_tests/data/$var5"
done

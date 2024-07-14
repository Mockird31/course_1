#!/bin/bash

read pos
read neg 

for (( i=1; i<=pos; i++ )); do
	var1="pos_0"$i"_in.txt"
	var2="pos_0"$i"_out.txt"
	touch $var1
	touch $var2
done

for (( i=1; i<=neg; i++ )); do
	var3="neg_0"$i"_in.txt"
	touch $var3
done

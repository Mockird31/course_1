#!/bin/bash

main="./*.sh"
scripts="./func_tests/scripts/*.sh"


for file in $main $scripts; do
	shellcheck "$file"
done


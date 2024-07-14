#!/bin/bash

./build_apps.sh 
./update_data.sh 3

python3 make_preproc.py
python3 make_postproc.py

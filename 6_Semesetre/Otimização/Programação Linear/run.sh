#!/bin/bash

make purge
make
clear
cat example.txt
./producao < example.txt
cat output.lp
lp_solve < output.lp
echo

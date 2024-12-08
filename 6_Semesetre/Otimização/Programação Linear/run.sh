#!/bin/bash

make purge
make
clear
cat input.txt
echo
./producao < input.txt
cat output.txt

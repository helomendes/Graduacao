#!/bin/bash

make purge
make
clear
cat entrada.txt
echo
./producao < entrada.txt

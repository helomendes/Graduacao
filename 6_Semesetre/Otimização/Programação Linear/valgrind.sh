#!/bin/bash

make purge
make
clear
cat entrada.txt
echo
valgrind --track-origins=yes -s ./producao < entrada.txt

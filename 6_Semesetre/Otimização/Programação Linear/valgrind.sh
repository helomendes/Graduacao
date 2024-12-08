#!/bin/bash

make purge
make
clear
cat input.txt
echo
valgrind --track-origins=yes -s --leak-check=full ./producao < input.txt
cat output.txt

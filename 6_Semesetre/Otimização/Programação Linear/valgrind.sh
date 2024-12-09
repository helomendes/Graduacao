#!/bin/bash

make purge
make
clear
cat example.txt
echo
valgrind --track-origins=yes -s --leak-check=full ./producao < example.txt
cat output.txt

#!/usr/bin/env zsh
g++ sort.cpp
echo "unpruned in C++:"
#echo $(time ./a.out < sort11.in > /dev/null) | grep user
time ./a.out < sort11.in > /dev/null
echo $(time ./a.out < sort12.in > /dev/null) | grep user
gcc sort.c
echo "unpruned in C:"
echo $(time ./a.out < sort11.in > /dev/null) | grep user
echo $(time ./a.out < sort12.in > /dev/null) | grep user
gcc sort-pruned.c
echo "pruned in C:"
echo $(time ./a.out < sort11.in) | grep user
echo $(time ./a.out < sort12.in) | grep user

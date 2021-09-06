#!/bin/sh

rm "test.txt"
make &&  ./push_swap 1 -3 20 7 11 -1 -2 > test.txt
#vim test.txt

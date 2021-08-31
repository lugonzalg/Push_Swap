#!/bin/sh

rm "test.txt"
make && ./push_swap 10 0 1 16 2 123 924 43 54 12 3 76 434 44 9 > test.txt

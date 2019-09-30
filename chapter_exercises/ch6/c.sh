#!/bin/bash

#
# A script which takes the number of exercise to compile and run as an argument,
# and, well, does just that!
#


NUM=$1

if [ $NUM == 1 ]
then
	g++ 6_1.cpp && ./a.out
elif [ $NUM == 2 ]
then
	g++ 6_2.cpp ./6_0/chapter_code/chapter_code.cpp && ./a.out
fi

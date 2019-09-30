#!/bin/bash

#
# A script which takes the number of exercise to compile and run as an argument,
# and, well, does just that!
#


NUM=$1

if [ $NUM == 2 ]
then
	g++ 6_2.cpp ./6_0/chapter_code/chapter_code.cpp && ./a.out
elif [ $NUM == 5 ] 
then
	g++ 6_5.cpp ./6_0/student/student.cpp ./6_0/student/lib/*.cpp && ./a.out
else
	g++ 6_$NUM.cpp && ./a.out
fi

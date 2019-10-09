#!/bin/bash

if [ $1 == 100 ]
then
	echo "NOTHING"
#	g++ 8_$1.cpp ../ch5/5_0/chapter_code/chapter_code.cpp && ./a.out
else
	g++ 8_$1.cpp && ./a.out
fi

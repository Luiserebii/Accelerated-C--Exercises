#!/bin/bash

if [ $1 == 3 ]
then
	g++ 7_$1.cpp ../ch5/5_0/chapter_code/chapter_code.cpp && ./a.out
else
	g++ $1 && ./a.out
fi

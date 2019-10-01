#!/bin/bash

if [ $1 == 1 ]
then
	g++ counting-words.cpp && ./a.out
elif [ $1 == 2 ]
then
	g++ cross-reference.cpp ../../ch5/5_0/chapter_code/chapter_code.cpp && ./a.out
else
	g++ $1 && ./a.out
fi

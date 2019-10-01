#!/bin/bash

if [ $1 == 2 ]
then
	g++ cross-reference.cpp ../../ch5/5_0/chapter_code/chapter_code.cpp && ./a.out
fi

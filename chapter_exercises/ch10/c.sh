#!/bin/bash

if [ $1 == 6 ]
then
        g++ 10_$1.cpp ./10_5/string_list.cpp && ./a.out
else
        g++ 10_$1.cpp && ./a.out
fi

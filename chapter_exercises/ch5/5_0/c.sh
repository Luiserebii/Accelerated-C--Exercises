#Compilation script vars

MAIN=$1
LIB=lib
CHAPTER_CODE=chapter_code/chapter_code.cpp


#Default compilation to main.cpp if nothing specified

if [ -z $1 ]
then
   MAIN=main.cpp
fi

#The actual execution:

g++ -std=c++11 $MAIN $LIB/*.cpp $CHAPTER_CODE

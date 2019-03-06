MAIN=$1
LIB=lib
CHAPTER_CODE=chapter_code.cpp

g++ -std=c++11 $MAIN $LIB/*.cpp $CHAPTER_CODE

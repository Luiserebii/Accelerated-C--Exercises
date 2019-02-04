

//Here's my first attempt:

/*
#include
<iostream>

int
main
(
)

{

std
::
cout
<<
"
H
e
l
l
o
,
 
w
o
r
l
d
!
"
<<
std
::
endl;
return
0
;
}
*/


// It failed, with output:

/*

0_10.cpp:5:9: error: #include expects "FILENAME" or <FILENAME>
0_10.cpp:19:1: warning: missing terminating " character
 "
 ^
0_10.cpp:19:1: error: missing terminating " character
0_10.cpp:33:1: warning: missing terminating " character
 "
 ^
0_10.cpp:33:1: error: missing terminating " character
0_10.cpp:6:1: error: expected unqualified-id before ‘<’ token
 <iostream>
 ^

*/


// Hmmm, darn, ok. I guess directives and strings may be an exception to free flow? Let's see:

#include <iostream>

int
main
(
)

{

std
::
cout
<<
"Hello, world!"
<<
std
::
endl;
return
0
;
}

//This one seems to have passed, alright, neat!

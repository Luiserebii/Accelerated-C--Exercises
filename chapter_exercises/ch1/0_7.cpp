
//
//This will likely fail to run, since /* will continue to parse until it hits */. Since it hits the first */ after "/* and ", it'll just cut off there and leave the rest as code.
//

//Test run:



#include <iostream>

int main()
{
    /* This is a comment that extends over several lines
    because it uses /* and */ as its starting and ending delimiters */

    std::cout << "Does this work?" << std::endl;
    return 0;
}


/*

Yup, failure to compile, as expected:

0_7.cpp: In function ‘int main()’:
0_7.cpp:13:31: error: ‘as’ was not declared in this scope
     because it uses / * and * / as its starting and ending delimiters * /
                                 ^


NOTE: Above comment characters have space in between in order to prevent compiler from interpreting it incorrectly; nested comments are not possible

*/


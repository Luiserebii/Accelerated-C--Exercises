#include <iostream>
#include "string.h"

using std::cout;
using std::endl;

int main() {

    Str s = "meme";
    cout << "s value: " << s << endl;
    cout << "c_str(): " << s.c_str() << endl;

    Str a = "apple";
    Str b = "banana";
    //Test relational operators
    cout << (a < b) << (a > b) 
        << (a <= b) << (a >= b) 
        << endl;

}  

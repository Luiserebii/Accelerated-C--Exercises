#include <iostream>
#include "string.h"

using std::cin;
using std::cout;
using std::endl;
using std::boolalpha;

int main() {

    Str s = "meme";
    cout << "s value: " << s << endl;
    cout << "c_str(): " << s.c_str() << endl;

    Str test;
    getline(cin, test);
    cout << test << endl;
}  

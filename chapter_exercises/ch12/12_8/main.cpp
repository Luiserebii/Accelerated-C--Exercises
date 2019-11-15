#include <iostream>
#include "string.h"

using std::cout;
using std::endl;
using std::boolalpha;

int main() {

    Str s = "meme";
    cout << "s value: " << s << endl;
    cout << "c_str(): " << s.c_str() << endl;

    Str::iterator i = s.begin();
    while(i != s.end()) {
        cout << *i++ << endl;
    }
}  

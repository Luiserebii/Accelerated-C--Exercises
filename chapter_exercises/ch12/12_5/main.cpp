#include <iostream>
#include "string.h"

using std::cout;
using std::endl;
using std::boolalpha;

int main() {

    Str s = "meme";
    cout << "s value: " << s << endl;
    cout << "c_str(): " << s.c_str() << endl;

    cout << boolalpha;
    cout << "meme == meme: " << (s == "meme") << endl;
    cout << "meme == uguu: " << (s == "uguu") << endl;
}  

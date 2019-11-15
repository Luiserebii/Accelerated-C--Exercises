#include <iostream>
#include "string.h"
#include "vector.h"

using std::cin;
using std::cout;
using std::endl;
using std::boolalpha;

int main() {

    Str s = "meme";
    cout << "s value: " << s << endl;
    cout << "c_str(): " << s.c_str() << endl;
    Vec<char> v(s.begin(), s.end());
    Str t(s.begin(), s.end());
    cout << "Vector value: " << t << endl;

}  

#include <iostream>
#include "string.h"

using std::cout;
using std::endl;
using std::boolalpha;

int main() {

    Str s = "meme";
    cout << "s value: " << s << endl;
    cout << "c_str(): " << s.c_str() << endl;

    //Just run these and see if they work
    cout << s + "uguu" << endl;
   // cout << ("uguu" + s) << endl;
}  

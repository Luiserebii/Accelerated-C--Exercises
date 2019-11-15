#include <iostream>
#include "string.h"

using std::cout;
using std::endl;

int main() {

    Str s = "meme";
    cout << "s value: " << s << endl;
    cout << "c_str(): " << s.c_str() << endl;
    cout << "data(): " << s.data_impl() << endl;
    char* t = new char[2];
    s.copy(t, 2);
    cout << "copy(): " << *t << *(t + 1) << endl;

    //Cleanup
    delete[] t;
}  

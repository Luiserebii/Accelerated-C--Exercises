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

    /**
     * I don't quite know why it wasn't asked us to reimplement the input
     * operator with istream_iterator; does it have to do with being able
     * to unget()? Couldn't we just call it on the original stream?
     */
}  

#include "string.h"
#include <iostream>

using std::istream;

istream& operator>>(istream& is, Str& s) {

    //Obliterate existing value(s)
    s.data.clear();

    //Read and discard leading whitespace
    char c;
    while(is.get(c) && isspace(c));

    //If still something to read, do so until next whitespace character
    if(is) {
        do {
            s.data.push_back(c);
        } while(is.get(c) && !isspace(c));
    
        //If we've read whitespace, place it back on the stream - unget
        if(is) {
            is.unget();
        }
    }
}

Str operator+(const Str& s, const Str& t) {
    Str r = s;
    r += t;
    return r;
}

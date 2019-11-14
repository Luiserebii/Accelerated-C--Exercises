#include "string.h"
#include <iostream>

using std::istream;
using std::ostream;

istream& operator>>(istream& is, Str& s) {

    //Obliterate existing value(s)
    s.destroy();

    //Read and discard leading whitespace
    char c;
    while(is.get(c) && isspace(c));

    //If still something to read, do so until next whitespace character
    if(is) {
        do {
            //This part is tricky...
            s.data.push_back(c);
        } while(is.get(c) && !isspace(c));
    
        //If we've read whitespace, place it back on the stream - unget
        if(is) {
            is.unget();
        }
    }
}

ostream& operator<<(std::ostream& os, const Str& s) {
    for(Str::size_type i = 0; i < s.size(); ++i) {
        os << s[i];
    }
    return os;
}


Str operator+(const Str& s, const Str& t) {
    Str r = s;
    r += t;
    return r;
}

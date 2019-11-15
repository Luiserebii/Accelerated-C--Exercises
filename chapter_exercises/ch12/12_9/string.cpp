#include "string.h"
#include <iostream>
#include <cstring>
#include <iterator>

using std::istream;
using std::ostream;
using std::strcmp;
using std::ostream_iterator;

//Stream operators
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
    s.updateCStr();
    return is;
}

istream& getline(istream& is, Str& s) {
    char delim = '\n';

    //Obliterate existing value(s)
    s.data.clear();

    //Read until delim
    if(is) {
        char c;
        while(is.get(c) && c != delim) {
            s.data.push_back(c);
        }
        //We hit the delim if we broke out; unget
        if(is) {
            is.unget();
        }
    }
    s.updateCStr();
    return is;
}

ostream& operator<<(ostream& os, const Str& s) {
    ostream_iterator<char> it(os);
    Str::const_iterator t = s.begin();
    while(t != s.end()) {
        *it++ = *t++;
    }
    //Alternatively, you can use std::copy(s.begin(), s.end(), it)
    return os;
}

//Concatenation
Str operator+(const Str& s, const Str& t) {
    Str r = s;
    r += t;
    return r;
}

Str operator+(const char* s, const Str& t) {
    Str r = s;
    r += t;
    return r;
}

Str operator+(const Str& s, const char* t) {
    Str r = s;
    r += t;
    return r;
}

//Relational operators
bool operator<(const Str& a, const Str& b) {
    return strcmp(a.c_str(), b.c_str()) < 0;
}

bool operator>(const Str& a, const Str& b) {
    return strcmp(a.c_str(), b.c_str()) > 0;
}

bool operator<=(const Str& a, const Str& b) {
    int c = strcmp(a.c_str(), b.c_str());
    return c < 0 || c == 0;
}

bool operator>=(const Str& a, const Str& b) {
    int c = strcmp(a.c_str(), b.c_str());
    return c > 0 || c == 0;
}

bool operator==(const Str& a, const Str& b) {
    return strcmp(a.c_str(), b.c_str()) == 0;
}

bool operator!=(const Str& a, const Str& b) {
    return !(strcmp(a.c_str(), b.c_str()) == 0);
}



//Copy, assignment, destructor
Str::Str(const Str& s) {
    //Relying on data's implemented assignment
    data = s.data;
    createCStr(s.c_str());
}

Str& Str::operator=(const Str& s) {
    //Check for self-assignment
    if(&s != this) {
        destroy();
        data = s.data;
        createCStr(s.c_str());
    }
    return *this;
}

Str::~Str() {
    //Supposedly, class members with defined destructors will be automatically
    //called after the manual destructor code
    destroy();
}

void Str::createCStr(const char* c) {
    //Create the c_str, now...
    size_t sz = strlen(c) + 1; //1 extra for the null termination
    char* n = new char[sz];
    char* t = n;
    for(size_t i = 0; i < sz; ++i) {
        *t++ = *c++;
    }
    //Set the internal c_str() to the copy
    cstr_raw = n;
}

void Str::updateCStr() {
    if(cstr_raw != 0) {
        delete[] cstr_raw;
    }
    char* n = new char[data.size() + 1]; //1 extra for the null termination
    //Temporary pointer
    char* t = n;
    Vec<char>::iterator i = data.begin();
    while(i != data.end()) {
        *t++ = *i++;
    }
    //Set the null character
    *t = '\0';
    //Finally, set the str;
    cstr_raw = n;
}

void Str::destroy() {
    delete[] cstr_raw;
}

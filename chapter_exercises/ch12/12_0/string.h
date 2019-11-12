#ifndef GUARD_String_h
#define GUARD_String_h

#include <algorithm>
#include <cstring>
#include <iostream>
#include "vector.h"

class Str {

    friend std::ostream& operator>>(std::istream& is, const Str& s);

    public:
        typedef Vec<char>::size_type size_type;

        //Default constructor
        Str() { }

        //Create a Str containing n copies of c char
        Str(size_type n, char c): data(n, c) { }

        //Create a Str from a null-terminated array of char
        Str(const char* cp) {
            std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
        }

        //Create a Str from the range denoted by iterators b and e
        template <class In>
        Str(In b, In e) {
            std::copy(b, e, std::back_inserter(data));
        }

        //Operators
        char& operator[](size_type i) { return data[i]; }
        const char& operator[](size_type i) const { return data[i]; }

        size_type size() const { return data.size(); }

    private:
        Vec<char> data;
};

inline 
std::ostream& operator<<(std::ostream& os, const Str& s) {
    for(Str::size_type i = 0; i < s.size(); ++i) {
        os << s[i];
    }
    return os;
}

#endif

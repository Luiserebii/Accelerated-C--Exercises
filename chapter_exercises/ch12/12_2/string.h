#ifndef GUARD_String_h
#define GUARD_String_h

#include <algorithm>
#include <cstring>
#include <iostream>
#include "vector.h"

class Str {

    friend std::istream& operator>>(std::istream& is, Str& s);

    public:
        typedef Vec<char>::size_type size_type;

        //Default constructor
        Str(): cstr_raw(0) { }

        //Create a Str containing n copies of c char
        Str(size_type n, char c): data(n, c), cstr_raw(0) { updateCStr(); }

        //Create a Str from a null-terminated array of char
        Str(const char* cp): cstr_raw(0) {
            std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
            updateCStr();
        }

        //Create a Str from the range denoted by iterators b and e
        template <class In>
        Str(In b, In e): cstr_raw(0) {
            std::copy(b, e, std::back_inserter(data));
            updateCStr();
        }

        //Copy, assignment, destructor
        Str(const Str&);
        operator=(const Str&);
        ~Str();


        //Operators
        char& operator[](size_type i) { return data[i]; }
        const char& operator[](size_type i) const { return data[i]; }

        Str& operator+=(const Str& s) {
            std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
            updateCStr();
            return *this;
        }

        size_type size() const { return data.size(); }
        char* c_str() { return cstr_raw; }

    private:
        Vec<char> data;
        char* cstr_raw;

        void createCStr(const Str&);
        void updateCStr();
        void destroy();
};

Str operator+(const Str& s, const Str& t);

inline 
std::ostream& operator<<(std::ostream& os, const Str& s) {
    for(Str::size_type i = 0; i < s.size(); ++i) {
        os << s[i];
    }
    return os;
}


#endif

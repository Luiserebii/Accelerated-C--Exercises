#ifndef GUARD_STRING_H
#define GUARD_STRING_H

#include <algorithm>
#include <cstring>
#include <iostream>

class Str {

    friend std::istream& operator>>(std::istream& is, Str& s);

    public:
        typedef size_t size_type;

        //Default constructor
        Str() { 
            data = 0;
            tail = 0;
        }

        //Create a Str containing n copies of c char
        Str(size_type n, char c) { 
            data = new char[n];
            tail = data + n;
        }

        //Create a Str from a null-terminated array of char
        Str(const char* cp) {
            size_t size = std::strlen(cp);
            data = new char[size];
            std::copy(cp, cp + size, data);
        }

        //Create a Str from the range denoted by iterators b and e
        template <class In>
        Str(In b, In e) {
            size_t size = e - b;
            std::copy(b, e, data);
        }

        //Operators
        char& operator[](size_type i) { return data[i]; }
        const char& operator[](size_type i) const { return data[i]; }

        Str& operator+=(const Str& s) {
            //Allocate new
            char* t = new char[s.length() + size()];
            //Copy to new
            std::copy(data, tail, t);
            //Destroy old
            delete[] data;
            //Copy new to new
            std::copy(s.begin(), s.end(), t);
            return *this;
        }

        size_type size() const { return tail - data; }

    private:
        char* data;
        char* tail;
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

#ifndef GUARD_STRING_H
#define GUARD_STRING_H

#include <algorithm>
#include <cstring>
#include <iostream>

class Str {

    friend std::istream& operator>>(std::istream& is, Str& s);

    public:
        typedef size_t size_type;
        typedef char* iterator;
        typedef const char* const_iterator;

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
            size_t sz = std::strlen(cp);
            data = new char[sz];
            std::copy(cp, cp + sz, data);
            tail = data + sz;
        }

        //Create a Str from the range denoted by iterators b and e
        template <class In>
        Str(In b, In e) {
            size_t sz = e - b;
            data = new char[sz];
            std::copy(b, e, data);
            tail = data + sz;
        }

        //Copy constructor, assignment op, destructor
        Str(const Str& s) {
            construct(s.begin(), s.end());
        }

        Str& operator=(const Str& s) {
            destroy();
            construct(s.begin(), s.end());
            return *this;
        }

        ~Str() {
            destroy();
        }

        //Operators
        char& operator[](size_type i) { return data[i]; }
        const char& operator[](size_type i) const { return data[i]; }

        Str& operator+=(const Str& s) {
            size_t new_size = size() + s.size();
            //Allocate new
            char* t = new char[new_size];
            //Copy to new
            std::copy(data, tail, t);
            //Copy new to new
            std::copy(s.begin(), s.end(), t + size());
            //Destroy old
            destroy();
            //Set to new
            data = t;
            tail = t + new_size;
            return *this;
        }

        Str& operator+=(const char& s) {
            size_t new_size = size() + 1;
            //Allocate new
            char* t = new char[new_size];
            //Copy to new
            std::copy(data, tail, t);
            //Copy new to new
            char* n = t + size(); 
            *n = s;
            //Destroy old
            destroy();
            //Set to new
            data = t;
            tail = t + new_size;
            return *this;
        }

        iterator begin() { return data; }
        const_iterator begin() const { return data; }

        iterator end() { return tail; }
        const_iterator end() const { return tail; }

        size_type size() const { return tail - data; }

    private:
        char* data;
        char* tail;

        void destroy();
        void construct(const char* b, const char* e);
};

Str operator+(const Str& s, const Str& t);
std::ostream& operator<<(std::ostream& os, const Str& s);
/*
void Str::destroy() {
    delete[] data;
    data = 0;
    tail = 0;
}

void Str::construct(const char* b, const char* e) {
    size_t new_size = e - b;
    data = new char[new_size];
    std::copy(b, e, data);
    tail = data + new_size;
}
*/
#endif

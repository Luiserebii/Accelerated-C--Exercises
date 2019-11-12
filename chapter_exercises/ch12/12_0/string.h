#ifndef GUARD_String_h
#define GUARD_String_h

#include <algorithm>

class Str {
    
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

    private:
        Vec<char> data;
}

#endif

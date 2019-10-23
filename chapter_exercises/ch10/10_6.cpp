#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

#include "10_5/string_list.h"

using std::cout;
using std::endl;
using std::string;

using std::find_if;
using std::isspace;

template <class Out>
void split(const std::string& str, Out os);

bool space(char c);
bool not_space(char c);

int main() {

    StringList s;
    s.push_back("Hello");
    s.push_back("world!");

    cout << "Printing string: " << endl;

    StringList::iterator it = s.begin();
    cout << *it++ << " " << *it << endl;
}


template <class Out>
void split(const string& str, Out os) {

    typedef string::const_iterator iter;

    iter i = str.begin();
    while(i != str.end()) {
        //Ignore leading blanks
        i = find_if(i, str.end(), not_space);

        //Find end of next word
        iter j = find_if(i, str.end(), space);

        //Copy the characters in [i, j)
        if (i != str.end())
            *os++ = string(i, j);

        i = j;
    }
}

// true if the argument is whitespace, false otherwise
bool space(char c) {
    return isspace(c);
}

// false if the argument is whitespace, true otherwise
bool not_space(char c) {
    return !isspace(c);
}


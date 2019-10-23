#include <iostream>
#include <string>

#include "string_list.h"

using std::cout;
using std::endl;
using std::string;

int main() {

    StringList s;
    s.push_back("Hello");
    s.push_back("world!");

    cout << "Printing string: " << endl;

    StringList::iterator it = s.begin();
    cout << *it++ << " " << *it << endl;
}


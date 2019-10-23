#include "string_list.h"
#include <string>
#include <algorithm>

using std::string;
using std::copy;

/**
 * Our other implementation, the psuedo-linked-list, we can't write a 
 * bi-directional iterator for without knowing how to write operations
 * for a class, so we will be using an internal array instead, and returning
 * the array pointer as an iterator (should give the same functionality)
 */

StringList::StringList() {
    a = NULL;
    size = 0;
}

void StringList::expand(size_t sz) {
    //If we're fresh, then initialize
    if(a == NULL) {
        a = new string[sz];
        size = sz;
    } else {
        //Create new array
        string* n = new string[sz];

        //Copy contents over
        copy(a, a + size, n);

        //Delete old array, set new one
        delete[] a;
        a = n;

        //Set new size
        size = sz;
    }
}

void StringList::push_back(string s) {
    //Increment and expand size by one
    expand(size + 1);
    
    //Set new blank element
    a[size - 1] = s;
}

string* StringList::getStringArr() {
    return a;
}

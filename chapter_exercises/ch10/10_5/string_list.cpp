#include "string_list.h"
#include <string>

using std::string;

/**
 * Our other implementation, the psuedo-linked-list, we can't write a 
 * bi-directional iterator for without knowing how to write operations
 * for a class, so we will be using an internal array instead, and returning
 * the array pointer as an iterator (should give the same functionality)
 */

StringList::StringList() {
    a = NULL;
}



void StringList::push_back(string s) {
    //If we're at the head, stick it in a new one
    if(a == NULL) {
        a = new string[0];
        *a = s;
    } else {
        
    }

}

string* StringList::getStringArr() {
    return a;
}

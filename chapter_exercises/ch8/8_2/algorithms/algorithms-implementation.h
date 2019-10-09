#ifndef GUARD_ALGORITHMS_IMPLEMENTATION_h
#define GUARD_ALGORITHMS_IMPLEMENTATION_h

#include <iostream>
#include <vector>

#include "algorithms.h"

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::boolalpha;

using std::vector;


/**
 *
 * IDEA: MAKE VERSION OF READVECTOR/WRITEVECTOR WHICH TAKE ITERATORS
 *       BETTER YET: MAKE IT CONTAINER GENERIC FRIENDLY
 *
 **/

template <class T>
istream& readVector(vector<T>& v, istream& in) {
    T element;
    while(in >> element) {
        v.push_back(element);
    }
    //Clear any flags/errors post-EOF/other error
    in.clear();
    return in;
}

template <class T>
ostream& writeVector(const vector<T>& v, ostream& out) {
    for(typename vector<T>::const_iterator i = v.begin(); i != v.end(); ++i) {
        out << *i << " ";
    }
    out << endl;
    return out;
}

template <class InputIterator>
bool equal(InputIterator begin, InputIterator end, InputIterator begin2) {

    while(begin != end) {
        if(*begin++ != *begin2++) return false;
        /**
         * Shorthand, for below:
         *
         * begin++
         * begin2++
         **/
    }
    //If we hit here, it must be true, since everything was equal hitherto
    return true;

}


template <class InputIterator, class T>
bool find(InputIterator begin, InputIterator end, T val) {
    while(begin != end) {
        if(*begin++ == val) return true;
    }
    //If we hit here, we found nothing
    return false;
}


template <class InputIterator, class OutputIterator>
void copy(InputIterator begin, InputIterator end, OutputIterator destination) {
    while(begin != end) {
        //Advance both, and paste appropriate value to destination
        //In this case, ++ has higher priority, so what is being set
        //is the previous value to the previous one
        *destination++ = *begin++;
    }
}


#endif

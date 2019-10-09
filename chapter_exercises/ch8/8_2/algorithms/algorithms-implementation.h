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
void copyI(InputIterator begin, InputIterator end, OutputIterator destination) {
    while(begin != end) {
        //Advance both, and paste appropriate value to destination
        //In this case, ++ has higher priority, so what is being set
        //is the previous value to the previous one
        *destination++ = *begin++;
    }
}


template <class InputIterator>
bool search(InputIterator begin, InputIterator end, InputIterator begin2, InputIterator end2) {
    while(begin != end) {
        if(*begin == *begin2) {
            //Obtain copies of pairs of iterators so to not modify and break them
            //if we go through this process and end up finding an invalid sequence
            InputIterator b = begin;
            InputIterator b2 = begin2;
            
            while(b2 != end2) {
                //Adding clause to check if we hit the end, for if we did, at this point,
                //the range is clearly too large, so let's break here
                if(b2 == end) return false;

                //If we encounter any inequality at some point, we need to break the loop
                if(*b++ != *b2++) break;

                //However, if we've made it this far, and its the end...
                if(b2 == end2) return true;
            }
        }
        //Move begin up through the loop
        begin++;
    }
}

template <class InputIterator, class T>
InputIterator find_if(InputIterator begin, InputIterator end, bool predicate(T)) {
    while(begin != end) {
        predicate(begin) ? return begin : begin++;
    }
}



#endif

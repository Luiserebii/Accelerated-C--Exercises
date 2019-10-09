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
            
            //Testing this here whilst checking b2 == end2 below is probably very strange,
            //one can see this as a if(b2 != end2) while(true) wrapped up in one, however,
            //hmm... if this was the case first time looping, then we should just return
            //false at the very beginning if begin2 != end2, as this would be empty range
            //we'd be looping for
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
    //Return false, not found
    return false;
}

template <class InputIterator, class T>
InputIterator find_if(InputIterator begin, InputIterator end, bool predicate(T)) {
    while(begin != end) {
        if(predicate(*begin)) return begin;
        begin++;
    }
    return end;
}


template <class InputIterator, class OutputIterator, class T>
OutputIterator remove_copy(InputIterator begin, InputIterator end, OutputIterator destination, T val) {
    //Strategy: Iterate through range, only add ones not to be removed to destination
    while(begin != end) {
        if(*begin != val) *destination++ = *begin++;
    }
    //This should be the end by now, so this satisfies the requirement
    //of returning last iterator in asymmetric range
    return destination;
}

template <class InputIterator, class OutputIterator, class T>
OutputIterator remove_copy_if(InputIterator begin, InputIterator end, OutputIterator destination, bool predicate(T)) {
    while(begin != end) {
        if(!predicate(*begin)) *destination++ = *begin++;
    }
    //This should be the end by now, so this satisfies the requirement
    //of returning last iterator in asymmetric range
    return destination;
}

/**
 * IMPORTANT REGARDING LOGIC ON THIS FUNCTION: CHECK 6.4:
 * Algorithms, containers, and Iterators (120)
 *
 * Essentially, the remove() functions really just move elements which should
 * stay to the front of the vector, leaving the rest alone, and finally, providing
 * an iterator pointing to the first of removable elements, thus allowing .erase()
 * to be called smoothly on it (.erase(res, c.end()))
 *
 * Just realized; no swap happens, it's just set to the beginning, for example: 
 *
 * 0 1 2 3 4 5 6 7 8 9 10
 *
 * Becomes:
 *
 * 1 3 5 7 9 5 6 7 8 9 10
 *
 * post-remove_if(v.begin(), v.end(), isEven)
 *
 * For proof, see attached .cpp as testStdRemove.cpp
 *
 **/
template <class ForwardIterator, class InputIterator, class T>
ForwardIterator remove(ForwardIterator begin, InputIterator end, T val) {
    ForwardIterator swapptr = begin;
    while(begin != end) {
        //If we have a value we want to preserve
        if(*begin != val) {
            //Set the swap pointer (place where we can put valid values at beginning)
            //and increment
            *swapptr++ = *begin++;
        } else {
            begin++;
        }
    
    }
    return swapptr;
}


#endif

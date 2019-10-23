#ifndef GUARD_median_h
#define GUARD_median_h

#include <algorithm>
#include <stdexcept>

/**
 * Note post-10.3 testing program:
 *
 * This is a bit of an awkward implementation here; we rely on being passed
 * a value, which doesn't matter in the program, but we use it in order to
 * determine the typing return value for the template during the whole
 * compile-link-process. 
 *
 * The limitation of this, is that it does not work for containers that do 
 * not support random-access iterators like lists.
 *
 */
template <class RandomAccess, class T>
T median(RandomAccess begin, RandomAccess end, T){

    //size_t for generic size of an object
    size_t size = 0;
    for(RandomAccess i = begin; i != end; ++i) {
        ++size;
    }
    if(size == 0)
        throw std::domain_error("median of an empty container");

    //Sort numerically
    std::sort(begin, end);

    //Obtain midpoint index
    size_t mid = size/2;
    return size % 2 == 0 ? (*(begin + mid) + *(begin + mid - 1)) / 2 : *(begin + mid);

}

#endif

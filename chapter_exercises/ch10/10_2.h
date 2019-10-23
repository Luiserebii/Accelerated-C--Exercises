#ifndef GUARD_median_h
#define GUARD_median_h

#include <algorithm>
#include <stdexcept>

template <class RandomAccess, class T>
T median(RandomAccess begin, RandomAccess end){

    //size_t for generic size of an object
    size_t size = 0;
    for(RandomAccess i = begin; i != end; ++i) {
        ++size;
    }
    if(size == 0)
        throw std::domain_error("median of an empty container");

    //Sort numerically
    sort(begin, end);

    //Obtain midpoint index
    size_t mid = size/2;
    return size % 2 == 0 ? (*(begin + mid) + *(begin + mid - 1)) / 2 : *(begin + mid);

}

#endif

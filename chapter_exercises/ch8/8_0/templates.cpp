#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

using std::vector;
using std::domain_error;
using std::sort;

template <class T>
T median(vector<T> v);


int main() {

    return 0;
}


// Template header
template <class T>
T median(vector<T> v) {
    typedef typename vector<T>::size_type vec_sz;
    vec_sz size = v.size();
    if(size == 0) {
        throw domain_error("median of an empty vector");
    }
    //Sort numerically
    sort(v.begin(), v.end());
    //Obtain midpoint index
    vec_sz mid = size/2;

    return size % 2 == 0 ? (v[mid] + v[mid-1]) / 2 : v[mid];
}

/**
 * Sequential read-only access
 *
 * In - Type of input iterator (read-only)
 * X  - Type of value to compare
 **/
template <class In, class X> In find(In begin, In end, const X& x) {
    while(begin != end && *begin != x)
        ++begin;
    return begin;
}

/**
 * Sequential write-only access
 *
 * In  - Type of input iterator
 * Out - Type of output iterator to write to (write-nly)
 **/
template <class In, class Out>
Out copy(In begin, In end, Out dest) {
    while(begin != end)
        *dest++ = *begin++;
    return dest;
}





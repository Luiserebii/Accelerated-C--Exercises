#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;

using std::vector;
using std::domain_error;
using std::sort;
using std::find_if;
using std::string;
using std::isspace;

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


/**
 * Sequential read-write access
 *
 * For - Type of forward iterator - a combo of read-only and write-only in a unifying way
 * X   - Type of element to manipulate (defining val to change to, when encountering some val)
 **/
template <class For, class X>
void replace(For begin, For end, const X& x, const X& y) {
    while(begin != end) {
        if(*begin == x)
            *begin = y;
        ++begin;
    }
}

/**
 * Reversible access
 *
 * Bi - Type of bidirectional iterator -  forward iterator, plus -- operation supported
 *
 **/
template <class Bi> void reverse(Bi begin, Bi end) {
    while(begin != end) {
        --end;
        if(begin != end)
            swap(*begin++, *end);
    }
}

/**
 * Random access
 *
 * Ran - Type of random-access iterator - forward iterator, plus basic arithmetic support
 * X   - Value to search for
 **/
template <class Ran, class X>
bool binary_search(Ran begin, Ran end, const X& x) {
    while(begin < end) {
        //Find the midpoint of the range
        Ran mid = begin + (end - begin) / 2;

        //See which part of the range contains x; keep looking only in that part
        if(x < *mid)
            end = mid;
        else if (*mid < x)
            begin = mid + 1;
        //If we got here, then *mid == x, so we're finished!
        else return true;
    }
}

template <class Out>
void split(const string& str, Out os) {
    
    typedef string::const_iterator iter;

    iter i = str.begin();
    while(i != str.end()) {
        //Ignore leading blanks
        i = find_if(i, str.end(), not_space)
    
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


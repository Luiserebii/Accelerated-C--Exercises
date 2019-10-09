#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

using std::vector;


template <class InputIterator>
bool equal(InputIterator begin, InputIterator end, InputIterator begin2);

template <class T>
istream& readVector(vector<T>& v, istream& in);

template <class T> 
ostream& writeVector(const vector<T>& v, ostream& out);

int main() {
    
    cout << "Welcome! Please enter a set of int elements delineated by a space, followed by EOF: " << endl;

    vector<int> v1;
    readVector(v1, cin);

    cout << "Writing your vector: " << endl;
    writeVector(v1, cout);

    return 0;

}


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
    for(vector<T>::const_iterator i = v.begin(); i != v.end(); ++i) {
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

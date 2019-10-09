#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::boolalpha;

using std::vector;


template <class InputIterator>
bool equal(InputIterator begin, InputIterator end, InputIterator begin2);

template <class InputIterator, class T>
bool find(InputIterator begin, InputIterator end, T val);

template <class T>
istream& readVector(vector<T>& v, istream& in);

template <class T> 
ostream& writeVector(const vector<T>& v, ostream& out);

int main() {
    
    cout << "Welcome! Please enter a set of int elements delineated by a space, followed by EOF, or unexpected input: " << endl;

    vector<int> v1;
    readVector(v1, cin);

    cout << "Another one: " << endl;

    vector<int> v2;
    readVector(v2, cin);

    cout << endl << endl << "Writing your vectors: " << endl;
    writeVector(v1, cout);
    writeVector(v2, cout);
    cout << endl;

    cout << "Are they equal?  " << boolalpha << equal(v1.begin(), v1.end(), v2.begin()) << endl;
    cout << "Let's try finding an element, please input an int that may exist in the first vector: " << endl;
    int el;
    cin >> el;
    cout << "Does " << el << " exist?  " << boolalpha << find(v1.begin(), v1.end(), el) << endl;

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




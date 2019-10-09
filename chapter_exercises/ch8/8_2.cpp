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
void writeVector(const vector<T>& v, ostream& out);

int main() {
    
    v

    return 0;

}

template <class T>
void writeVector(const vector<T>& v, ostream& out) {
    for(vector<T>::const_iterator i = v.begin(); i != v.end(); ++i) {
        out << *i << " ";
    }
    out << endl;
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

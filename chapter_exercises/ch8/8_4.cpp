#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::vector;

template <class Bi> void reverse(Bi begin, Bi end);
template <class Bi> void reverseStd(Bi begin, Bi end);
template <class T>
void swap(T& val1, T& val2);

template <class T>
std::istream& readVector(std::vector<T>& v, std::istream& in);

template <class T>
std::ostream& writeVector(const std::vector<T>& v, std::ostream& out);


int main() {

    cout << "Please enter an int vector: " << endl;
    vector<int> v;
    readVector(v, cin);
    vector<int> vc = v;

    //Test our implemntation with swap
    cout << "Our implementation: " << endl;
    reverse(v.begin(), v.end());
    writeVector(v, cout);

    //Test standard library
    cout << "Standard library implementation (std::swap)" << endl;
    reverseStd(vc.begin(), vc.end());
    writeVector(vc, cout);

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

template <class Bi> void reverseStd(Bi begin, Bi end) {
    while(begin != end) {
        --end;
        if(begin != end)
            std::swap(*begin++, *end);
    }
}

template <class T>
void swap(T& val1, T& val2) {
    T temp = val1;
    val1 = val2;
    val2 = temp;
}


template <class T>
std::istream& readVector(std::vector<T>& v, std::istream& in) {
    T element;
    while(in >> element) {
        v.push_back(element);
    }
    //Clear any flags/errors post-EOF/other error
    in.clear();
    return in;
}

template <class T>
std::ostream& writeVector(const std::vector<T>& v, std::ostream& out) {
    for(typename std::vector<T>::const_iterator i = v.begin(); i != v.end(); ++i) {
        out << *i << " ";
    }
    out << std::endl;
    return out;
}


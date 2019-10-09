#include <iostream>
#include <vector>
#include <iterator>

#include "./algorithms/algorithms.h"

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::boolalpha;

using std::vector;
using std::back_inserter;

//Our test predicate
bool isEven(int i);

int main() {
    
    //Initialize first vector
    cout << "Welcome! Please enter a set of int elements delineated by a space, followed by EOF, or unexpected input: " << endl;
    vector<int> v1;
    readVector(v1, cin);

    //Initialize second vector
    cout << "Another one: " << endl;
    vector<int> v2;
    readVector(v2, cin);

    cout << endl << endl << "Writing your vectors: " << endl;
    writeVector(v1, cout);
    writeVector(v2, cout);
    cout << endl;

    //Testing equal(b, e, b2)
    cout << "Are they equal?  " << boolalpha << equal(v1.begin(), v1.end(), v2.begin()) << endl;

    //Testing find(b, e, t)
    cout << "Let's try finding an element, please input an int that may exist in the first vector: " << endl;
    int el;
    cin >> el;
    cout << "Does " << el << " exist?  " << boolalpha << find(v1.begin(), v1.end(), el) << endl;
    cout << endl;

    //Testing copyI(b, e, d)
    cout << "Now let's try copy from v1 to v2!" << endl;
    copyI(v1.begin(), v1.end(), back_inserter(v2));
    writeVector(v2, cout);
    cout << endl;

    //Testing search(b, e, b2, e2)
    cout << "How about search? Please type in a set of int elements that may be contained: " << endl;
    vector<int> sVec;
    readVector(sVec, cin);
    cout << "Is it within the first vector?  " << search(v1.begin(), v1.end(), sVec.begin(), sVec.end()) << endl;
    cout << endl;

    //Testing find_if(b, e, p)
    cout << "And find_if... let's see if we have an even number!" << endl;
    vector<int>::const_iterator fi_it = find_if(v1.begin(), v1.end(), isEven);
    bool isFound = fi_it != v1.end();
    cout << "Found?  " << isFound << endl;
    if(isFound) cout << "...and this value is: " << *fi_it << endl;
    cout << endl;

    //Testing remove_copy(b, e, d, t)
    cout << "And remove_copy... let's attempt to remove values from the first vector, return as copy" >> endl;
    vector<int> removeCopy;
    cout << "Enter a value to remove... ";
    int removeVal;
    cin >> removeVal;
    remove_copy(v1.begin(), v1.end(), back_inserter(removeCopy), removeVal);
    //Print v1 here to prove it is intact, alongside the copy post-remove
    cout << "v1: ";
    writeVector(v1, cout);
    cout << "removeCopy: ";
    writeVector(removeCopy, cout);
    cout << endl;

    return 0;

}

bool isEven(int i) {
    return i % 2 == 0;
}

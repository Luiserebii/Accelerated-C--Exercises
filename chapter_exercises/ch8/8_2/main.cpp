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
    cout << "Now let's try copy from v1 to v2!" << endl;
    copyI(v1.begin(), v1.end(), back_inserter(v2));
    writeVector(v2, cout);

    return 0;

}



#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>

using std::cout;
using std::endl;

using std::copy;
using std::back_inserter;
using std::vector;

using std::string;

void test();
size_t strlen(const char* p);

int main() {
    const size_t NDim = 3;
    double coords[NDim];

    double* e = coords;

    *e++ = 1.5;
    *e++ = 2.0;
    *e = 2.5;
    cout << coords[0] << " " << coords[1] << " " << coords[2] << endl;
    cout << "ADDR? " << &coords[0] << " " << &coords[1] << " " << " " << &coords[2] << endl; 

    vector<double> v;
    copy(coords, coords + NDim, back_inserter(v));
    cout << "COPY: ";
    for(vector<double>::iterator i = v.begin(); i < v.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;

    test();
}

void test() {
    const int month_lengths[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    // '\0' is a null character, forming a null-terminating string
    const char hello[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
    cout << "STRLEN: " << strlen(hello) << endl;

    //Creating a string from char*
    string s1(hello);

    //Creating a string from pointers (iterators)
    string s2(hello, hello + strlen(hello));

    cout << "s1: " << s1 << "    s2: " << s2 << endl;
}

//Like the <cstring> strlen, the null-terminating character is excluded
size_t strlen(const char* p) {
    size_t size = 0;
    while(*p++ != '\0')
        ++size;
    return size;
}

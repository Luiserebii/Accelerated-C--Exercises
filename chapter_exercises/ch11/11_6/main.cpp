#include "vector.h"
#include <iostream>

using std::ostream;
using std::cout;
using std::endl;

template <class T>
void print(T begin, T end, ostream& out=cout);

int main() {

    //Setting up a Vec
    Vec<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(8);
    print(v.begin(), v.end());

    //Attempt erase()
    v.erase(v.begin() + 3);
    print(v.begin(), v.end());
    


}

template <class T>
void print(T begin, T end, ostream& out) {
    while(begin != end) {
        out << *begin++ << " ";
    }
    out << endl;
}


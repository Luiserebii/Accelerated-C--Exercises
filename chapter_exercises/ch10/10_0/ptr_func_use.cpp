#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>

using std::cout;
using std::endl;

using std::time;
using std::srand;
using std::rand;
using std::vector;
using std::string;
using std::stringstream;

template <class In, class Pred>
In find_if(In begin, In end, Pred f);

bool is_negative(int n);

template <class T>
void fillVector(vector<T>& v, typename vector<T>::size_type lim);

template <class T>
string toStringVector(const vector<T>& v);

template <class In>
string toStringContainer(In begin, In end);


int main() {

    srand(time(NULL));
    vector<int> v;

    fillVector(v, 10);
    cout << "vector: " << toStringVector(v);
}

template <class In, class Pred>
In find_if(In begin, In end, Pred f) {

    while(begin != end && !f(*begin))
        ++begin;
    return begin;
}

bool is_negative(int n) {
    return n < 0;
}

template <class T>
void fillVector(vector<T>& v, typename vector<T>::size_type lim) {
    for(typename vector<T>::size_type i = 0; i < lim; ++i) {
        int n = rand() % 10;
        if(rand() % 5 == 0)
            n *= -1;
        v.push_back(n);
    }
}

template <class T>
string toStringVector(const vector<T>& v) {
    return toStringContainer(v.begin(), v.end());
}

template <class In>
string toStringContainer(In begin, In end) {
    stringstream ss;
    while(begin != end) { 
        ss << *begin++ << " "; 
    }
    ss << endl;
    return ss.str();
}

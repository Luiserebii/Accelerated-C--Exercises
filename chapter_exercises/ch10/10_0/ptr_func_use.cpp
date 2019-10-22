#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using std::cout;
using std::endl;

using std::time;
using std::srand;
using std::rand;
using std::vector;

template <class In, class Pred>
In find_if(In begin, In end, Pred f);

bool is_negative(int n);

template <class T>
fillVector(vector<T>& v, vector<T>::size_type lim);

template <class T>
toStringVector(const vector<T>& v);

template <class In>
toStringContainer(T begin, T end);


int main() {

    srand(time(NULL));
    vector<int> v;


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
fillVector(vector<T>& v, vector<T>::size_type lim) {
    for(vector<T>::size_type i = 0; i < lim; ++i)
        v.push_back(rand() % 10);
}

template <class T>
toStringVector(const vector<T>& v) {
    return toStringContainer(v.begin(), v.end());
}

template <class In>
toStringContainer(T begin, T end) {
    string s = "";
    while(begin != end)
        s += *begin++;
        s += " ";
    return s;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>

using namespace std;

template <class T>
istream& readVector(vector<T>& v, istream& in);
template <class T>
ostream& writeVector(const vector<T>& v, ostream& out);
bool isEven(int n);

int main() {
  std::cout << "Hello World!\n";
  vector<int> v;
  cout << "uguu~" << endl;
  readVector(v, cin);
  remove_if(v.begin(), v.end(), isEven);
  writeVector(v, cout);
  cout << "END OF PROGRAM" << endl;
}

template <class T>
istream& readVector(vector<T>& v, istream& in) {
  T element;
  try { 
  while(in >> element) {
    v.push_back(element);
  }
  } catch(exception) {}
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

bool isEven(int n) {
  return n % 2 == 0;
}

/**
 *
 * Output: 
 *
 * Hello World!
 * uguu~
 * 0 1 2 3 4 5 6 7 8 9 10
 * 1 3 5 7 9 5 6 7 8 9 10
 * END OF PROGRAM
 *
 */


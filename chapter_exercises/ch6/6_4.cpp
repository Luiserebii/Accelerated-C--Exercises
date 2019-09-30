#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::vector;
using std::copy;
using std::back_inserter;
using std::stringstream;
using std::string;

void fixOne();
void fixTwo();

string vectorToString(const vector<int>& v);

int main() {

    /**
     * This fragment initializes a vector with 10 elements, all being 10.
     * All elements in u, i.e. these two, will be attempted to be added to v;
     * however, since it is not initialized and have no size, this should
     * do some strange things depending on the implementation, as it will be
     * accessing strange memory locations, could very well break;
     *
     * vector<int> u(10, 100);
     * vector<int> v;
     * copy(u.begin(), u.end(), v.begin());
     */

//    fixOne();
    fixTwo();
    return 0; 
}

/**
 * One fix: simply provide a back_inserter to expand the size of the container
 */
void fixOne() {
    vector<int> u(10, 100);
    vector<int> v;
    copy(u.begin(), u.end(), back_inserter(v));

    cout << vectorToString(v);
}

/**
 * Another fix: simply allocate space beforehand
 */
void fixTwo() {
    vector<int> u(10, 100);
    vector<int> v(10);
    copy(u.begin(), u.end(), v.begin());

    cout << vectorToString(v);
}


string vectorToString(const vector<int>& v) {
    stringstream ss;
    typedef vector<int>::const_iterator iter;
    for(iter i = v.begin(); i != v.end(); ++i) {
        ss << *i << endl;
    }
    return ss.str();
}

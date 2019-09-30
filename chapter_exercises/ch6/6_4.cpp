#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;

using std::vector;
using std::copy;
using std::back_inserter;

void fixOne();
void fixTwo();

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

    fixOne();
    return 0; 
}

/**
 * One fix: simply provide a back_inserter to expand the size of the container
 */
void fixOne() {
    vector<int> u(10, 100);
    vector<int> v;
    copy(u.begin(), u.end(), back_inserter(v));
    cout << "v: " << v[0] << "    " << v[1] << endl;

}

#include <iostream>

template <class InputIterator>
bool equal(InputIterator begin, InputIterator end, InputIterator begin2);

int main() {
    return 0;
}


template <class InputIterator>
bool equal(InputIterator begin, InputIterator end, InputIterator begin2) {

    while(begin != end) {
        if(*begin++ != *begin2++) return false;
        /**
         * Shorthand, for below:
         *
         * begin++
         * begin2++
         **/
    }
    //If we hit here, it must be true, since everything was equal hitherto
    return true;

}

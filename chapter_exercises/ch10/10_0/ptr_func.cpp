#include <iostream>

using std::cout;
using std::endl;

int next(int n);

int main() {

    int (*fp)(int);
    
    //Set pointer to next; note that 
    //using a function's val (next) will
    //decay into &next by default
    //
    //Therefore, this can also be fp = next; with no issue
    fp = &next;

    //The same is true with using a function, calling
    //a pointer to a function will dereference it by default
    //
    //Therefore, this can also be fp(n) with no issue
    int i = 0;
    i = (*fp)(i);
    cout << i << endl;


}

int next(int n) {
    return n + 1;
}



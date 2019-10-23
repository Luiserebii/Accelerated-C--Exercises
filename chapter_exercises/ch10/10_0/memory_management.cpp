/**
 * Outlining different kinds of memory management
 */
#include <iostream>

using std::cout;
using std::endl;

void automatic();
int* getStaticPointer();
int* dynamic();

int main() {

    int* meme = dynamic();
    cout << "Obtained var at address: " << meme << endl;
    cout << "Here's the val: " << *meme << endl;
    *meme = 100000;
    cout << "Changed to: " << *meme << endl;
    cout << "Deallocating now" << endl;
    delete meme;
    cout << "Address stays?: " << meme << endl;
    cout << "...and, what if we read? " << *meme << endl;
}


/**
 * Automatic: system allocates memory to local variables and frees
 * on end of scope
 *
 */
void automatic() {
    //Memory for x allocated
    int x = 5;
    return; //Destroyed on return
}

/**
 * Static: Statically allocated memory is memory allocated *once*.
 * Not intended for deallocation for the life of the program.
 *
 */
int* getStaticPointer() {
    //Allocate this memory as soon as the program begins! Only one
    //space for this var.
    static int x;
    return &x; //return the pointer to the static var
}

/**
 * Dynamic: Dynamically allocated memory, which allocates and de-allocates
 * memory on request.
 *
 * Typically uses "new" and "delete" keywords.
 *
 */
int* dynamic() {
    //Allocate memory for an int
    int* p = new int(99);

    //Return the pointer; this will not be destroyed on end of scope
    return p; 
}

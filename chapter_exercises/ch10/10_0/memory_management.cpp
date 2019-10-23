/**
 * Outlining different kinds of memory management
 */



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
    return &x; // return the pointer to the static var
}

/

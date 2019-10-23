#include <iostream>

using std::cout;
using std::endl;


//argc: number of pointers in the array
//argv: a pointer to the init. element in an array of pointers
int main(int argc, char** argv) {

    //If we have any args,
    if(argc > 1) {
        //Write the first argument
        cout << argv[1];

        for(int i = 2; i != argc; ++i)
            cout << " " << argv[i];
    }
    cout << endl;
    return 0;
}

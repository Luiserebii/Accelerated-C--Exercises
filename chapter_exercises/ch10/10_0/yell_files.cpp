#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cerr;
using std::endl;

using std::ifstream;

using std::string;
using std::getline;

/**
 * 
 * Screams all files passed onto the terminal, if not found, spits to the standard error stream
 *
 */
int main(int argc, char** argv) {
    int fail_count = 0;

    //For each file in the input list
    for(int i = 1; i < argc; ++i) {
        ifstream in(argv[i]);
    
        //If it exists, write contents, otherwise generate an error message
        if(in) {
            string s;
            while(getline(in, s))
                cout << s << endl;
        
        } else {
            cerr << "cannot open file " << argv[i] << endl;
            ++fail_count;
        }
    }
    //Return the numbers of fails found as exit code
    return fail_count;

}

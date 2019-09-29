#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>

using std::isspace;
using std::string;
using std::vector;

using std::isspace;

int main() {











}

// true if the argument is whitespace, false otherwise
bool space(char c) {
    return isspace(c);
}

// false if the argument is whitespace, true otherwise
bool not_space(char c) {
    return !isspace(c);
}

vector<string> split(const string& str) {
    typedef string::const_iterator iter;
    vector<string> ret;

    iter i = str.begin();
    while(i != str.end()) {
        //Look for an iterator pointing to element which is not a space
        i = find_if(i, str.end(), not_space);
        //Find end of next word
        iter j = find_if(i, str.end(), space);
        //Copy the characters in [i, j), assuming we haven't hit the end in looking for a non-space character
        if(i != str.end()) {
            //Add this new string, using iterators as the range
            ret.push_back(string(i, j));
        }
        //Push our loop "pointer" up
        i = j;
    
    }
    return ret;
}

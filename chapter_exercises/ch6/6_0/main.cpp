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
    vector<string> strs;

    iter i = str.begin();
    while(i != str.end()) {
        i = find_if(i, str.end(), not_space);

    
    }
}

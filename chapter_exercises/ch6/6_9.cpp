#include <iostream>
#include <vector>
#include <string>

#include <numeric> 

using std::cin;
using std::cout;
using std::endl;

using std::vector;
using std::string;
using std::accumulate;

string concatenateVector(const vector<string>&);
string vectorToString(const vector<string>& v);


int main() {

    vector<string> test;
    test.push_back("Hello!");
    test.push_back("from");
    test.push_back("a planet called");
    test.push_back("Mars");
    cout << "Printing current vector: " << endl;
    cout << vectorToString(test);

    string meme = concatenateVector(test);
    cout << "accumulate: " << meme << endl;


}

string concatenateVector(const vector<string>& v) {
    return accumulate(v.begin(), v.end(), "");
}

string vectorToString(const vector<string>& v) {
    string s;
    typedef vector<string>::const_iterator iter;
    for(iter i = v.begin(); i != v.end(); ++i) {
        s += *i;
        s += "\n";
    }
    return s;
}


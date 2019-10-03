#include <iostream>
#include <string>
#include <vector>
#include <map>

//#include "../ch5/5_0/chapter_code/chapter_code.h"
#include "../ch6/6_0/chapter_code/chapter_code.h"

using std::cin;
using std::cout;
using std::endl;
using std::istream;

using std::string;
using std::getline;
using std::vector;
using std::map;

map<string, vector<int> > xref(istream& in, vector<string> find_words(const string&) = split);

int main() {
    
    map<string, vector<int> > ret = xref(cin);

    for(map<string, vector<int> >::const_iterator i = ret.begin(); i != ret.end(); ++i) {
        //Write the first word
        cout << i->first << " occurs on line(s): ";

        //And next, the line numbers:
        vector<int>::const_iterator line_it = i->second.begin();
        //Write the first one, and...
        cout << *line_it;
        ++line_it;
        //..the rest, if any
        while(line_it != i->second.end()) {
            cout << ", " << *line_it;
            ++line_it;
        }
        cout << endl;
    }
    return 0;
}

/**
 * Cross-referencing function, which will take input from any stream, a function to acquire a vector<string>
 * of words from that stream (like split, as default), and return a mapping of strings to vector<ints>, 
 * representing their locations found by line number
 */
map<string, vector<int> > xref(istream& in, vector<string> find_words(const string&)) {
    string line;
    int line_number = 0;
    map<string, vector<int> > ret;

    //Loop through each line
    while(getline(in, line)) {
        ++line_number;
        //Grab words in this specific line
        vector<string> words = find_words(line);
        //For each word...
        for(vector<string>::const_iterator i = words.begin(); i != words.end(); ++i) {
            //Target the string in the map and push_back the line number
            ret[*i].push_back(line_number);
        }
    }
    return ret;
}



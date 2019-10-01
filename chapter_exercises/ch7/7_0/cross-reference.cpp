#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "../../ch5/5_0/chapter_code/chapter_code.h"

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

    return 0;
}

/**
 * Cross-referencing function, which will take input from any stream, a function to acquire a vector<string>
 * of words from that stream (like split, as default), and return a mapping of strings to vector<ints>, 
 * representing their locations found by line number
 */
map<string, vector<int> > xref(istream& in, vector<string> find_words(const string&) = split) {
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



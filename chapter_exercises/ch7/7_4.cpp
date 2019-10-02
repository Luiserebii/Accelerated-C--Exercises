#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "../ch5/5_0/chapter_code/chapter_code.h"

using std::cin;
using std::cout;
using std::endl;
using std::istream;

using std::stringstream;
using std::string;
using std::getline;
using std::vector;
using std::map;

using std::find;

map<string, vector<int> > xref(istream& in, vector<string> find_words(const string&) = split);

int main() {
    
    map<string, vector<int> > ret = xref(cin);

    for(map<string, vector<int> >::const_iterator i = ret.begin(); i != ret.end(); ++i) {

        /**
         * In the solution below, I am making a compromise between "active feedback" and
         * buffering output by keeping it in a string, which we will need to actively
         * keep track of the number of chars we will print. This is why nextToWrite
         * will "flush" every so often
         */

        const int MAX_LIMIT_CHAR_NUM = 40;
        stringstream next;
        int char_number = 0;

        //Create the first line
        next << i->first << " occurs on line(s): ";
        char_number += next.str().length();

        //Print here to "buffer"
        cout << next.str();
        next.str("");

        //And next, the line numbers:
        vector<int>::const_iterator line_it = i->second.begin();
        //Write the first one, and...
        next << *line_it;
        //Ensure to keep track of number of chars in current line (counting from addition to string)
        char_number += next.str().size();
        ++line_it;
        //..the rest, if any
        

        while(line_it != i->second.end()) {

            stringstream temp;
            temp << ", " << *line_it;
            //If under the limit,
            if(char_number + temp.str().length() < MAX_LIMIT_CHAR_NUM) {
                //Add it to our psuedo-buffer
                next << temp.str();
                //Advance char_number
                char_number += temp.str().length();
            } else {
                //Otherwise, make a line, and add it
                next << endl << temp.str();

                //And set the new char_number appropriately
                char_number = temp.str().length();
            }
            ++line_it;
        }
        //Finally, print the rest of the line
        cout << next.str() << endl;

/*
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
*/
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
            //Target the string in the map and push_back the line number, only if not found
            //if(find(ret[*i].begin(), ret[*i].end(), line_number) == ret[*i].end()) {
                ret[*i].push_back(line_number);
            //}
        }
    }
    return ret;
}



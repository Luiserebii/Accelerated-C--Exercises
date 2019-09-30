#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>

#include "chapter_code.h"

using std::isspace;
using std::string;
using std::vector;

using std::isspace;
using std::isalnum;

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

bool is_palindrome(const string& s) {
    //Use equal() in passing the iterators for the full string, and check if equal to a range of iterators;
    //equal() assumes the sizes of the pairs of iterators is the same, so it progressively iterates
    //through the third iterator with the same length.
    //
    //Since rbegin() will provide a reverse iterator, it will head backwards on ++, thus providing what we want;
    //checking each element in reverse with the non-reverse counterpart :)
    return equal(s.begin(), s.end(), s.rbegin());
}

vector<string> find_urls(const string& s) {
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();

    while(b != e) {
        
        //Grab an iterator pointing to the beginning of a potential URL
        b = url_beg(b, e);
    
        //If we indeed found something
        if(b != e) {
            //Get the rest of the URL
            iter after = url_end(b, e);

            ret.push_back(string(b, after));

            //Advance b
            b = after;
        }
    }
}

string::const_iterator url_end(string::const_iterator b, string::const_iterator e) {
    //Return an iterator pointing at a non-URL char
    return find_if(b, e, not_url_char);
}

bool not_url_char(char c) {
    static const string url_ch = "~;/?:@=&$-_.+!*`(),";
    //If we've not found it within our character metric (looking within the string and not hitting the end) or is
    //alphanumeric, return the inverse    
    return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e) {
    static const string sep = "://";
    typedef string::const_iterator iter;

    iter i = b;
    //Loop through searching "://" within the range [i, e), and ensure we don't hit the end
    while((i = search(i, e, sep.begin(), sep.end())) != e) {
        //If the seperator isn't at the beginning of end of the line...
        if(i != b && i + sep.size() != e) {
            //Mark beginning of the protocol name
            iter beg = i;
            //While the char before beg iterator is alpha, iterate backwards
            //NOTE: Seems like iterators can be "indexed" (beg[-1] just refers to iterator before that one)
            while(beg != b && isalpha(beg[-1])) {
                --beg;
            }

            //If we have at least one valid cover before and after the seperator, good!
            if(beg != i && !not_url_char(i[sep.size()])) {
                return beg;
            }
        }
        //Continue on, skip over seperator we found, as it is not a URL
        i += sep.size();
    }
}

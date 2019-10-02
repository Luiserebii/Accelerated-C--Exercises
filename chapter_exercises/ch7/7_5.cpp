#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <exception>
#include <cstdlib>

#include "../ch5/5_0/chapter_code/chapter_code.h"

using std::istream;
using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::getline;
using std::vector;
using std::list;
using std::map;

using std::domain_error;
using std::logic_error;
using std::rand;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

Grammar read_grammar(istream& in);
list<string> gen_sentence(const Grammar& g);
bool bracketed(const string& s);
void gen_aux(const Grammar& g, const string& word, list<string>& ret);
int nrand(int n);

/**
 * ===============
 *  Sample input:
 * ===============
 * 
 * <noun> cat
 * <noun> dog
 * <noun> table
 * <noun-phrase> <noun>
 * <noun-phrase> <adjective> <noun-phrase>
 * <adjective> large
 * <adjective> brown
 * <adjective> absurd 
 * <verb> jumps
 * <verb> sits
 * <location> on the stairs
 * <location> under the sky
 * <location> wherever it wants
 * <sentence> the <noun-phrase> <verb> <location>
 *
 */

int main() {

    //Generate a sentence
    list<string> sentence = gen_sentence(read_grammar(cin));

    //Write the first word
    list<string>::const_iterator it = sentence.begin();
    if(!sentence.empty()) {
        cout << *it;
        ++it;
    }

    //Write the rest of the words, each preceeded by a space
    while(it != sentence.end()) {
        cout << " " << *it;
        ++it;
    }

    cout << endl;
    return 0;
}

Grammar read_grammar(istream& in) {
    Grammar ret;
    string line;
   
    //Loop through each line 
    while(getline(in, line)) {
        //Grab a line, in words
        vector<string> entry = split(line);

        //Assuming it isn't empty,
        if(!entry.empty()) {
            //Using the first word as the map string value, push_back a new vector created utilizing the iterators
            //and thrown into the Rule() (and therefore, vector<string>) constructor
            ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
        }
    }
    return ret;
}

list<string> gen_sentence(const Grammar& g) {
    list<string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}

//Return whether string is bracked (like <this>) or not
bool bracketed(const string& s) {
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

void gen_aux(const Grammar& g, const string& word, list<string>& ret) {
    //If the word isn't bracketed, then we can feel free to push it as is
    if(!bracketed(word)) {
        ret.push_back(word);
    } else {
        //Grab the rule
        Grammar::const_iterator it = g.find(word);
        if(it == g.end()) {
            throw logic_error("empty rule");
        }
        //Grab a reference to the rule collection for that specific rule 
        //(i.e. the vector<string>)
        const Rule_collection& c = it->second;   
        //Randomly obtain a number
        const Rule& r = c[nrand(c.size())];

        for(Rule::const_iterator i = r.begin(); i != r.end(); ++i) {
            gen_aux(g, *i, ret);
        }
    }
}

/**
 * Return a random integer in an assymetric range [0, n)
 *
 * Implementation: Idea is that, with a large enough number, or any number in which 
 * RAND_MAX % x != 0, there will be overlap, repeats/places where some numbers will become more
 * likely than others (think of very large numbers near RAND_MAX, like 2000; only one value
 * can yield 2000, whereas 2 can do 1500)
 *
 * In order to avoid this, we employ logic to determine which "bucket" the number falls under.
 * If the random number generated is too large, it will fall out of range of these evenly
 * numbered buckets entirely, and be tossed for another (check the while loop)
 *
 * Ex: if n = 3, [0, 10922), [10922, 21844) will yield 1, [21844, 32766) will yield 2, and overlap
 * (32766 and 32767 will be discarded)
 */
int nrand(int n) {
    if (n <= 0 || n > RAND_MAX) {
        throw domain_error("Argument to nrand is out of range");
    }
    const int bucket_size = RAND_MAX / n;
    int r;

    do { 
        r = rand() / bucket_size;
    } while(r >= n);

    return r;
}

#include <iostream>
#include <vector>
#include <map>
#include <string>

using std::istream;
using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::getline;
using std::vector;
using std::map;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

Grammar read_grammar(istream& in);

int main() {

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

vector<string> gen_sentence(const Grammar& g) {
    vector<string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}

//Return whether string is bracked (like <this>) or not
bool bracketed(const string& s) {
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

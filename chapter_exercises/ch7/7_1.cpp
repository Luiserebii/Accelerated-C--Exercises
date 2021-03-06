#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;

using std::string;
using std::vector;
using std::map;

ostream& writeGroupedOccurences(ostream& out, const map<string, int>& m);
void mapGroupOccurences(const map<string, int>& m, map<int, vector<string> >& groupOccurences);

int main() {
    string s;
    map<string, int> counters;

    while (cin >> s) {
        ++counters[s];
    }

    for(map<string, int>::const_iterator it = counters.begin(); it != counters.end(); ++it) {
        cout << it->first << "\t" << it->second << endl;
    }
    writeGroupedOccurences(cout, counters);

    return 0;
}

ostream& writeGroupedOccurences(ostream& out, const map<string, int>& m) {
    out << "Ordered by occurence count: " << endl << endl;
    map<int, vector<string> > groupOccurences;
    mapGroupOccurences(m, groupOccurences);
    for(map<int, vector<string> >::const_iterator i = groupOccurences.begin(); i != groupOccurences.end(); ++i) {
        //Write the int
        out << i->first << ": " << endl;
        //Iterate over vector<string> and print each thingie
        for(vector<string>::const_iterator j = i->second.begin(); j != i->second.end(); ++j) {
            out << "    " << *j << endl;
        }
        cout << endl;
    }
    return out;
}

void mapGroupOccurences(const map<string, int>& m, map<int, vector<string> >& groupOccurences) {
    for(map<string, int>::const_iterator i = m.begin(); i != m.end(); ++i) {
        groupOccurences[i->second].push_back(i->first);
    }
}

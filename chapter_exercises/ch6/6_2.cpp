#include <vector>
#include <string>

#include "./6_0/chapter_code/chapter_code.h"

using std::vector;
using std::string;

string vectorToString(const vector<string>& v); //Need to place this into some sort of personal util thing

int main() {

    const string urlString = "Projects: https://serebii.io/projects/Github: https://github.com/LuiserebiiGitea (Mirror): serebii.io:2501Youtube: UChTayiHQFSy-ltWf0qGrsAgTwitter: https://twitter.com/luiserebiiPeepeth: 0x2c0851d263c3508d5b048dc0b712a816ef18371fEmail: luis@serebii.ioDiscord: Luiserebii#0001";

    cout << "Your string: " << urlString << endl;
    vector<string> myUrls = find_urls(urlString);
    cout << "Output: " << vectorToString(myUrls);

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

#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;

using std::vector;
using std::string;

using std::max;
using std::transform;
using std::back_inserter;

std::string::size_type width(const std::vector<std::string>& v);
vector<string> frame(const vector<string>& v);
vector<string> hcat(const vector<string>& left, const vector<string>& right);

string vectorToString(const vector<string>& v);

int main() {

    vector<string> test;
    test.push_back("Hello!");
    test.push_back("from");
    test.push_back("a planet called");
    test.push_back("Mars");
    cout << "Printing currrent vector: " << endl;
    cout << vectorToString(test);

    test = frame(test);
    cout << "Printing post-framing: " << endl;
    cout << vectorToString(test);
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


vector<string> frame(const vector<string>& v){

   vector<string> ret;
   string::size_type maxlen = width(v);

   //Construct border as 2 more *s on each side
   string border(maxlen + 4, '*');
   ret.push_back(border);

   //write each interior row...
   for(vector<string>::const_iterator i = v.begin(); i != v.end(); ++i){
      //...bordered by an asterisk and space
      ret.push_back("* " + *i + string(maxlen - (*i).size(), ' ') + " *");
   }

   //Finally, add the bottom border
   ret.push_back(border);
   return ret;

}

vector<string> hcat(const vector<string>& left, const vector<string>& right){

   vector<string> ret;

   //Add 1 to leave a one-space margin between squares
   string::size_type width1 = width(left) + 1;

   vector<string>::size_type i = 0, j = 0;

   while(i != left.size() || j != right.size()){

      //Construct new string to hold characters from both pictures
      string s;

      //Copy a row from the left-hand side, if there is one
      if(i != left.size())
         s = left[i++];

      //Pad to full width
      s += string(width1 - s.size(), ' ');

      //Copy a row from the right-hand side, if there is one
      if(j != right.size())
         s += right[j++];

      //Finally, add the row to the vector
      ret.push_back(s);

   }

   return ret;

}

string::size_type width(const vector<string>& v){

   string::size_type maxlen = 0;
   for(vector<string>::size_type i = 0; i < v.size(); ++i)
      //Getting the largest size string in the vector
      maxlen = max(maxlen, v[i].size());
   return maxlen;

}


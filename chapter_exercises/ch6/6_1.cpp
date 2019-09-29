#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

using std::max;

std::string::size_type width(const std::vector<std::string>& v);
vector<string> frame(const vector<string>& v);
vector<string> hcat(const vector<string>& left, const vector<string>& right);

int main() {


}

vector<string> frame(const vector<string>& v){

   vector<string> ret;
   string::size_type maxlen = width(v);

   //Construct border as 2 more *s on each side
   string border(maxlen + 4, '*');
   ret.push_back(border);

   //write each interior row...
   for(vector<string>::size_type i = 0; i != v.size(); ++i){
      //...bordered by an asterisk and space
      ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
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


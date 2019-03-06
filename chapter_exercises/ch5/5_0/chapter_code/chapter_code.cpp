#include "chapter_code.h"

#include <string>
#include <vector>
#include <list>

#include <algorithm>
#include <cctype>


using std::string;
using std::vector;
using std::list;

using std::max;
using std::isspace; 



vector<string> split(const string& s){

   vector<string> ret;
   typedef string::size_type string_size;
   string_size i = 0;

   while(i != s.size()){
    
      while(i != s.size() && isspace(s[i]))
         ++i;

      //find end of next word
      string_size j = i;

      while(j != s.size() && !isspace(s[j]))
         ++j;

      //if we found some nonwhitespace characters
      if(i != j){
         //copy from s starting at i and taking j - i chars
         ret.push_back(s.substr(i, j - i));
         i = j;
      }

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

/*
vector<string> vcat(const vector<string>& top, const vector<string>& bottom){

}

vector<string> hcat(const vector<string>& left, const vector<string>& right){

}

*/

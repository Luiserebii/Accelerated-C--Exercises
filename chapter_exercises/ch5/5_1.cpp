/*

Design and implement a program to produce a permuted index. A permuted index is
one in which each phrase is indexed by every word in the phrase. So, given the following
input,

The quick brown fox 
jumped over the fence

the output would be

         The quick     brown fox 
   jumped over the     fence
   The quick brown     fox 
                       jumped over the fence
            jumped     over the fence
               The     quick brown fox 
       jumped over     the fence
                       The quick brown fox

A good algorithm is suggested in "The AWK Programming Language" by Aho, Kernighan, and
Weinberger (Addison-Wesley, 1988). That solution divides the problem into three steps:

1. Read each line of the input and generate a set of rotations of that line. Each rotation
puts the next word of the input in the first position and rotates the previous first word
to the end of the phrase. So the output of this phase for the first line of our input would
be

   The quick brown fox
   quick brown fox The
   brown fox The quick
   fox The quick brown

Of course, it will be important to know where the original phrase ends and where the
rotated beginning begins.

2. Sort the rotations.
3. Unrotate and write the permuted index, which involves finding the separator, putting
the phrase back together, and writing it properly formatted.

*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::setw;

using std::istream;
using std::vector;
using std::string;

using std::max;

vector<string> readToRotations(istream& is);
vector<string> generateRotations(vector<string>& rotations, string str);
void rotate(string& str);
bool compareRotations(const string& a, const string& b);
string getRotatedEnd(const string& str);
string getRotatedBeginning(const string& str);
void printRotatedVector(const vector<string>& v);

int main() {
   
   //For each line of input...
      //Read a line of input, receive cin
      
   //Return vector<string> of rotations 
   //Sort function for vectors
/*   
   string str; getline(cin, str);
   cout << "STR: " << str; rotate(str); cout << "    ROTATED: " << str; 

   getline(cin, str);
   vector<string> rotations = generateRotations(str);

   typedef vector<string>::iterator vstr_it;

   for(vstr_it it = rotations.begin(); it != rotations.end(); ++it){
      cout << *it << endl;
   } 
  */ 

   //Read the rotations
   vector<string> rotations = readToRotations(cin);


   cout << "ROTATIONS READ" << endl;
   //Sort them
   sort(rotations.begin(), rotations.end(), compareRotations);

   for(int i = 0; i < rotations.size(); ++i) cout << rotations[i] << endl;


   cout << "ROTATIONS SORTED" << endl;
   //Print them
   printRotatedVector(rotations);
   cout << "ROTATIONS PRINTED" << endl;
   
}

vector<string> readToRotations(istream& is){

   vector<string> rotations;

   string line;
   while(getline(is, line)){
      generateRotations(rotations, line);
   }
   return rotations;   
}


//Let's just take this as a copy, since we'll be manipulating this
vector<string> generateRotations(vector<string>& rotations, string str){

   str += "&";   
   //Keep track of initial state
   string init = str;
   rotations.push_back(init);
   //Rotate to keep invariant true
   rotate(str);

   //Invariant: initial string is not the same as next rotated one
   while(init != str){  
      rotations.push_back(str);
      rotate(str);
   }
   
   return rotations;
   
}


//Rotate reference of string
void rotate(string& str){
   string::size_type end = str.find(" ");
   //It is assumed we have whitespace following the word:
   str = str.substr(end + 1, str.size()) + " " + str.substr(0, end);
   return;
}


bool compareRotations(const string& a, const string& b){
   return getRotatedEnd(a) < getRotatedEnd(b);
}



//Simply gets the rotated end post-delimiter, since this is alphabetically sorted this is what we're going for
string getRotatedEnd(const string& str){

   string delimiter = "&";
   string strEnd;

   //The end is considered the first piece before the &
   if(str.find(delimiter) != 0){
      strEnd = str.substr(0, str.find("&"));
   } else {
      strEnd = "";
   }

   return strEnd;

}

string getRotatedBeginning(const string& str){

   string delimiter = "&";
   string strBeg;

   //The end is considered the first piece before the &
   //cout << "ISHERE:  " << str.find(delimiter) << endl;
   //cout << "SIZE:   " << str.size() << endl;
   if(str.find(delimiter) != 0){
      strBeg = str.substr(str.find(delimiter) + 1);
   } else {
      strBeg = "";
   }
   //cout << "STR: " << str << "ROTATEDBEGINNING:   " << strBeg;

   return strBeg;

}


void printRotatedVector(const vector<string>& v){

   typedef vector<string>::const_iterator v_iter;
   typedef string::size_type str_type;

   //Find greatest length for beg and end
   str_type max_len_beg = 0;
   str_type max_len_end = 0;   

   for(v_iter it = v.begin(); it != v.end(); ++it){
      max_len_beg < getRotatedBeginning(*it).size() ? max_len_beg = getRotatedBeginning(*it).size()
                                                    : max_len_beg;
      max_len_end < getRotatedEnd(*it).size() ? max_len_end = getRotatedBeginning(*it).size()
                                                    : max_len_end;      
   }

   //Now, loop through to print based on max_len:
   for(v_iter it = v.begin(); it != v.end(); ++it){
      cout << setw(max_len_beg) << getRotatedBeginning(*it) << "    " << setw(max_len_end) << getRotatedEnd(*it) << endl;
   }
   return;

}














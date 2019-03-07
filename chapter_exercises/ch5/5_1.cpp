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
#include <vector>
#include <string>


using std::cin;
using std::cout;
using std::endl;

using std::istream;
using std::vector;
using std::string;

vector<string> readToRotations(istream& is);
vector<string> generateRotations(string str);
void rotate(string& str);
 


int main() {
   
   //For each line of input...
      //Read a line of input, receive cin
      
   //Return vector<string> of rotations 
   //Sort function for vectors
   
   string str; getline(cin, str);
   cout << "STR: " << str; rotate(str); cout << "    ROTATED: " << str; 

   getline(cin, str);
   vector<string> rotations = generateRotations(str);

   typedef vector<string>::iterator vstr_it;

   for(vstr_it it = rotations.begin(); it != rotations.end(); ++it){
      cout << *it << endl;
   } 
   
   
}

/*
vector<string> readToRotations(istream& is){

   vector<string> rotations;

   string line;
   while(getline(is, line)){

      

   }


}
*/

//Let's just take this as a copy, since we'll be manipulating this
vector<string> generateRotations(string str){
   
   vector<string> rotations;
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





















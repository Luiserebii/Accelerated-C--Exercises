/*


Write a function that reads words from an input stream and stores them in a vector. 
Use that function both to write programs that count the number of words in the input, 
and to count how many times each word occurred.


*/

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::istream;

using std::string;
using std::vector;

struct wordOccurence {
   string word;
   int count;
}
 
vector<string> istreamToVector(istream &is);
int wordExists(vector<wordOccurence>, string);

int main(){

   vector<string> wordInput = istreamToVector(cin);

   //Number of words count
   cout << "NUMBER OF WORDS IN INPUT: " << wordInput.size();

   //Word occurence count
   
   vector<wordOccurence> wordOcc;
   typedef vec_size vector<wordOccurence>::size_type;

   for(vec_size i = 0; i < wordInput.size(); i++) {
      //if string input thing doesn't exist
         //add, with 1
      //else, add to count

      int exists = wordExists(wordOcc, wordInput[i]);
      exists == -1 ? wordOcc.push_back(wordInput[i], 1) : wordOcc[exists].count++;
     
   } 

   

}



vector<string> istreamToVector(istream &is){

   vector<string> stringVec;
   string str;

   while(is >> str){
      stringVec.push_back(str);
   }

   is.clear();
   return stringVec;

}

int wordExists(vector<wordOccurence> wordOcc, string word){

   typedef vec_size vector<wordOccurence>::size_type;
   for(vec_size i = 0; i < wordOcc.size(); i++)}{
      if(wordOcc[i] == word){
         return i;
      }
   }

   return -1;
}

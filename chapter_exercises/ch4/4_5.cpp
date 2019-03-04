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
};
 
//typedef vector<wordOccurence>::size_type vec_size;
typedef int vec_size;

vector<string> istreamToVector(istream &is);
int wordExists(vector<wordOccurence>, string);
void printWordOcc(vector<wordOccurence>);

int main(){

   vector<string> wordInput = istreamToVector(cin);

   //Number of words count
   cout << "NUMBER OF WORDS IN INPUT: " << wordInput.size();

   //Word occurence count   
   vector<wordOccurence> wordOcc;

   for(vec_size i = 0; i < wordInput.size(); i++) {
      //if string input thing doesn't exist
         //add, with 1
      //else, add to count

      int exists = wordExists(wordOcc, wordInput[i]);
      if(exists == -1){
         wordOccurence wo;
         wo.word = wordInput[i];
         wo.count = 1;

         wordOcc.push_back(wo);
      } else {
         wordOcc[exists].count++;
      }
     
   } 
 
   printWordOcc(wordOcc);   

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

   for(vec_size i = 0; i < wordOcc.size(); i++){
      if(wordOcc[i].word == word){
         return i;
      }
   }

   return -1;
}

void printWordOcc(vector<wordOccurence> wordOcc){

   for(vec_size i = 0; i < wordOcc.size(); i++){
      cout << i << " WORD:     " << wordOcc[i].word << "   COUNT:   " << wordOcc[i].count << endl; 
   }

}


/*

Write a program to count how many times each distinct word appears in its input.

*/

#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;


int main()
{

   //Welcome user, and ask for list of words
   cout << "Hello! Pass a list of words seperated by whitespace, and I will return the number of times a distinct word appears." << endl;

   //Declare unique word input
   int uniqueWordCounter = 0;

   //Read words into vector of strings
   vector<string> wordTracker;
   string word;  

   while(cin >> word){
      
      //Check existence
      bool isExists = false;
      
      //Loop through our wordTracker, try to prove eixtence
      for(vector<string>::size_type i = 0; i < wordTracker.size(); i++){
         if(word == wordTracker[i]){
            isExists = true;
         }
      }

      //If non-existent, add to vector,
      //add to uniquewordcounter  
      if(!isExists){
         wordTracker.push_back(word);
         ++uniqueWordCounter;
      }

   }

   cout << "There are " << uniqueWordCounter << " instances of unique words in the provided list." << endl;

}





/*

Write a program to report the length of the longest and shortest string in its input.

*/

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

using std::string;
using std::vector;


int main()
{

   //Declare integers; longest, shortest
   string::size_type longest, shortest;
   
   //Query first word
   cout << "Hello! Pass a list of strings, and I'll give you the sizes of the shortest and longest strings in the input." << endl;
   string word;
   cin >> word;

   //Set to longest/shortest
   longest = word.size();
   shortest = word.size();

   //Loop through rest
   while(cin >> word) {
      if(word.size() > longest) { longest = word.size(); }
      if(word.size() < shortest) { shortest = word.size(); }
   }

   //Print result
   cout << "The size of the longest string in the list was: " << longest << ", and the shortest was " << shortest << "." << endl;


}



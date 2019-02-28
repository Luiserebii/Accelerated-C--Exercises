/*

Write a program to compute and print the quartiles (that is, the quarter of the numbers with the largest values, the next highest quarter, and so on) of a set of integers 

*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::vector;

int main() {


   cout << "Hello, and welcome! Please enter a series of numbers, the total of which is a multiple of 4." << endl;

   //While there's still stuff to read,
   //Get stuff and push_back into vector
   vector<int> totalNums;

   int num;
   while(cin >> num){
      totalNums.push_back(num);
   }   

   //Get size of the total vector
   std::vector<int>::size_type vectorSize = totalNums.size();

   if(vectorSize % 4 != 0) { cout << "ERROR: NOT MULTIPLE OF 4"; return 1;}

   //Divide thing by 4 (if not a multiple of 4, throw error)
   vector<int>::size_type numPerQuartile = vectorSize / 4;

   //Let's order the thing, by non-decreasing order...
   std::sort(totalNums.begin(), totalNums.end());

   //For multiples of 4,
   //print shit
   for(int i = 0; i < 4; i++){
      for(int j = 0; j < numPerQuartile; j++){
         cout << totalNums[i*numPerQuartile + j] << " ";
      }
      cout << endl;
   }

   return 0;
}






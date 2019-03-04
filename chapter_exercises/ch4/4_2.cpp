/*

Write a program to calculate the squares of int values up to 100. The program
should write two columns: The first lists the value; the second contains the square
of that value. Use setw (described above) to manage the output so that the values 
line up in columns.

*/

#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::endl;
//setw is simply the manipulator equivalent for istream.width(n)
using std::setw;
//By looking up the docs, we can see this returns streamsize, which is good for precision
using std::streamsize;

using std::pow;


int square(int x);


int main(){
   
   //for each up to 100

   int columnMargin = 10;
   //print 1st normally
   //square is setw(10)

   for(int i = 0; i <= 100; ++i){
      
      //This line
      streamsize prev = cout.width();
      cout << i << setw(columnMargin) << square(i) << endl;
      //and this one is likely not necessary since we are told they reset the width, but we will use it anyways for good practice.
      cout.width(prev);
      
   }


}


int square(int x){
   return pow(x,2);
}

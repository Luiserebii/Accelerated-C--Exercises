/*

Now change your squares program to use double values instead of ints. Use
manipulators to manage the output so that the values line up in columns.

*/


#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
//setw is simply the manipulator equivalent for istream.width(n)
using std::setw;
//By looking up the docs, we can see this returns streamsize, which is good for precision
using std::streamsize;

using std::pow;

using std::string;
using std::stringstream;

int numDigits(double n);
double square(double x);
bool printSquares(double max);

int main(){

   bool success = printSquares(1.3);
   success ? cout << "SUCCESS" << endl : cout << "FAILURE" << endl;

}

bool printSquares(double max){

   //Calculate a good column margin; let's say, 8 + the amount of chars max can take up?
   int offset = 8;
   int columnMargin = offset + numDigits(max);

   for(double i = 0; i <= max; i+=0.01){

      //This line
      streamsize prev = cout.width();
      cout << i << setw(columnMargin) << square(i) << endl;
      //and this one is likely not necessary since we are told they reset the width, but we will use it anyways for good practice.
      cout.width(prev);

   }

   return true;

}


double square(double x){
   return pow(x,2);
}

int numDigits(double n){

   int digits = 0;

   std::stringstream ss;
   ss << n;

   string s = ss.str();
   //If we have a . in the string, just subtract 1 from the size of the string
   s.find(".") != -1 ? digits = s.size() - 1: digits = s.size();   

   return digits;
}

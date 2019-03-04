/*

What happens if we rewrite the previous program to allow values up to
but not including 1000, but neglect to change the arguments to setw? 

Rewrite the program to be more robust in the face of changes that allow i 
to grow without adjusting the setw arguments.

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


int numDigits(int n);
int square(int x);
bool printSquares(int max);

int main(){

   bool success = printSquares(1000);
   success ? cout << "Execution successful!" << endl : cout << "Failure" << endl;

}

bool printSquares(int max){

   //Calculate a good column margin; let's say, 8 + the amount of chars max can take up?
   int offset = 8;
   int columnMargin = offset + numDigits(max);

   for(int i = 0; i <= max; ++i){

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

int numDigits(int n){

   int digits = 1;
  
   while(n > 9){
      n /= 10;
      digits++;
   }

   return digits;
}

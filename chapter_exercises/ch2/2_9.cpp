//Ask user for two numbers, tell user which number is larger

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){

   //Declare two numbers
   int a;
   int b;

   //Query for two numbers
   cout << "Hello! Please enter two numbers, and I'll tell you which one is larger." << endl;

   //Grab both numbers
   //Since cin chains, we can grab the next piece left in the stream
   cin >> a >> b;

   //Apply logic, print based on logic
   if(a > b){
      cout << "The first one, " << a << ", is larger than " << b << "!" << endl;
   } else if(b > a){
      cout << "The second one, " << b << ", is larger than " << a << "!" << endl;
   } else{
      cout << "Both numbers are equal: " << a << " and " << b << "!" << endl;
   }

}



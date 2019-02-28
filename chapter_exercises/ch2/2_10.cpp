/*

Explain each of the uses of std:: in the following program: 

*/

#include <iostream>

int main()
{
   int k = 0;
   while (k != 10) {
      using std::cout; //A using declaration to claim usage over "cout", and have it assumed to be std::. Done within the temporary block scope.
      cout << "*";
      ++k;
   }
   std::cout << std::endl; //Usage of explicitly defined qualified name with the scope operator to tell the compiler to use the "endl" within the namespace std.
   return 0;
}


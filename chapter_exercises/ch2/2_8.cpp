//Write a program to generate the product of the numbers in the range [1,10)

#include <iostream>

using std::cout;
using std::endl;

int main()
{
   int product = 1;

   for(int i = 1; i < 10; i++){
      product *= i;
   }
   cout << "The product of the numbers in the range [1,10) is: " << product << endl;
}

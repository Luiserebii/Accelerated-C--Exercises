#include <iostream>
#include <string>


using std::cin;
using std::cout;
using std::endl;
using std::string;


int main() 
{
   //Query name
   cout << "Please enter your first name: ";

   //Read the name
   string name;
   cin >> name;

   //Build our greeting
   const string greeting = "Hello, " + name + "!";   

   //Padding of blanks around string
   const int pad = 0;

   //Calculate number of rows and columns to generate
   const int rows = pad * 2 + 3;
   const string::size_type cols = greeting.size() + pad * 2 + 2;

   //Blank newline to seperate output from input
   cout << endl;

   for(int r = 0; r != rows; ++r){
      string::size_type c = 0;

      while(c != cols) {
         if(r == pad + 1 && c == pad + 1) {

            cout << greeting;
            c += greeting.size();

         } else {

            if(r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
               cout << "*";
            else
               cout << " ";
            ++c;
         }
      }

      cout << endl;

   }

   return 0;
}

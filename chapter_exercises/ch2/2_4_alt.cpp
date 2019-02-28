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

   //Query side-padding
   cout << "How many spaces would you like to pad the greeting with on the sides? ";
   int side_pad_in;
   cin >> side_pad_in;

   //Padding of blanks around string
   const int side_pad = side_pad_in;
   const int margin_pad = 1;

   //Calculate number of rows and columns to generate
   const int rows = margin_pad * 2 + 3;
   const string::size_type cols = greeting.size() + side_pad * 2 + 2;

   //Blank newline to seperate output from input
   cout << endl;

   for(int r = 0; r != rows; ++r){
      string::size_type c = 0;

      while(c != cols) {
         if(r == margin_pad + 1 && c == side_pad + 1) {

            cout << greeting;
            c += greeting.size();

         } else {

            if(r == 0 || r == rows - 1 || c == 0 || c == cols - 1){
               cout << "*";
               ++c;
            } else if(r != rows/2){ //otherwise, if we're not on that starting row/qualifying column
               cout << std::string(cols - 2, ' ');
               c += cols - 2;
            } else { //Otherwise, if we are in the middle row:
               cout << std::string(side_pad, ' ');
               c += side_pad;
            }
         }
      }

      cout << endl;

   }

   return 0;
}

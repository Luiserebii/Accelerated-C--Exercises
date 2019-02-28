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
      //string::size_type c = 0;

           //If we're in the first or row before last...
            if(r == 0 || r == rows - 1){
               for(int i = 0; i < cols; ++i){
                  cout << "*";
               }

               //Make the invariant true to exit
               //c = cols;

            //Otherwise, if we're in the row where we just print a ton of spaces...
            } else if(r != rows/2){
               //Print first star
               cout << "*";
               //...and all the spaces...
               for(int i = 0; i < cols - 2; ++i){
                  cout << " ";
               }
               //And, close it
               cout << "*";

           } else {
                //Print first star
               cout << "*";
               //...and the first batch of margin...
               for(int i = 0; i < side_pad; ++i){
                  cout << " ";
               }
               cout << greeting;
               //...and the second batch of margin...
               for(int i = 0; i < side_pad; ++i){
                  cout << " ";
               }
               //And, close it
               cout << "*";
              
           }

           //Thus, the while loop is removed as we only need to iterate through the rows. We just print x per row, and move on.

      cout << endl;

   }

   return 0;
}

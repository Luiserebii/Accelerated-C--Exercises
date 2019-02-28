#include <iostream>
#include <string>


//Let's use these names for convenience
using std::cin;
using std::cout;
using std::endl;
using std::string;


int main()
{

   //Write * square
/*
   const int length = 5;

   for(int i = 0; i < length; i++){
      for(int j = 0; j < length; j++){
         cout << "*";
      }
      cout << endl;
   }
*/
   //Write * rectangle
/*
   const int length = 10;
   const int width = 5;

   for(int i = 0; i < width; i++){
      for(int j = 0; j < length; j++){
         cout << "*";
      }
      cout << endl;
   }
*/
   //Write * triangle

   const int length = 11;

   if(length % 2 == 0) {cout << "ERROR: INPUT MUST BE ODD"; return 1;}

   for(int i = 1; i < length; i+=2){
      std::string::size_type numberStars = i;
      std::string::size_type spaceMargin = (length - numberStars)/2;

      string margin = string(spaceMargin, ' ');
      string stars = string(numberStars, '*');

      cout << margin << stars << margin << endl;
   }   



   return 0;

}



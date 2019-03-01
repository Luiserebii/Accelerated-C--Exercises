/*

Write a program that will keep track of grades for several students at once. The program could keep two vectors in sync: The first should hold the student's names, and the second the final grades that can be computed as input is read. For now, you should assume a fixed number of homework grades. We'll see in §4.1.3/56 how to handle a variable number of grades intermixed with student names.

The functionality of the program as follows:

-Queries list of midterm and final exam grades
-Asks for all of homework grades, followed by EOF
-Calculates final grade, which is 20% midterm, 40% final, 40% homework 

*/

#include <iostream>
#include <string>
#include <vector>


using std::cout;
using std::cin;
using std::endl;

using std::string;
using std::vector;


int main()
{
   bool moreStudents = true;
   cout << "Hello! Ready to get started calculating the grades of several students?" << endl;

   //Declare vector of student strings and grades
   vector<string> studentNames; 
   vector<double> grades;

   //Loop asking for student
   while(moreStudents){
      


      cout << "Need to input more students? (Type \"y\", \"Y\", \"yes\" for yes, all other input considered as a no.)" << endl;
      string response;
      cin >> response;


      //At end, check if still has more students
      //set bool to false if input is not "y, Y, yes"
      
      if(!(response == 'y' || response == 'Y' || response == "yes" || response == "Yes" || response == "YES")){
         moreStudents = false;
      }

   }

   //Vomit all students along with final grades

   cout << "Excellent! We've just calculated your students' grades using our hyperfast C++ implementation. (jk)" << endl;
   cout << "Behold, your precious values: " << endl << endl;

   for(string::size_type i = 0; i < studentNames.size(); i++){
      cout << studentNames[i] << "     " << grades[i] << endl;
   }

   cout << "That's all bitch" << endl;

}




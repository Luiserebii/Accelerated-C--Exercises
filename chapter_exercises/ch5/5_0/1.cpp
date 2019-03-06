#include <iostream>
#include <string>
#include <vector>

#include "lib/student_lib.h"

using std::string;
using std::vector;

using std::cout;
using std::endl;

vector<Student_info> extract_fails(vector<Student_info>& students);

int main() {

   Student_info s1 = { "Floofy", 100, 100, {100, 100, 100} }; 
   Student_info s2 = { "Doot Doot", 0, 0, {60, 50}};
   Student_info s3 = { "Cake", 100, 80, {0}};
   Student_info s4 = { "Floofy-mega", 1000, 1000, {10000}};

   vector<Student_info> passing = {s1, s2, s3, s4};
   vector<Student_info> failing = extract_fails(passing);
    
   typedef vector<Student_info>::const_iterator student_iter;

   for(student_iter iter = passing.begin(); iter < passing.end(); ++iter){
      cout << "PASSING STUDENTS: " << (*iter).name << endl;

   }

}


vector<Student_info> extract_fails(vector<Student_info>& students){

   vector<Student_info> pass, fail;
   
   for(vector<Student_info>::size_type i = 0; i < students.size(); ++i){

      if(fgrade(students[i]))
         fail.push_back(students[i]);
      else
         pass.push_back(students[i]);      
      
   }

   students = pass;
   return fail;
   
}




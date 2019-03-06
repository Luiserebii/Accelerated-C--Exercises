#include <iostream>
#include <string>
#include <vector>

#include "chapter_code.h"

using std::string;
using std::vector;

using std::cout;
using std::endl;

void printStudentVector(vector<Student_info> stdVec, string str);


int main() {

   Student_info s1 = { "Floofy", 100, 100, {100, 100, 100} }; 
   Student_info s2 = { "Doot Doot", 0, 0, {60, 50}};
   Student_info s3 = { "Cake", 100, 80, {0}};
   Student_info s4 = { "Floofy-mega", 1000, 1000, {10000}};

   version1 v1;

   vector<Student_info> passing1 = {s1, s2, s3, s4};
   vector<Student_info> failing1 = v1.extract_fails(passing1);

 
   printStudentVector(passing1, "PASSING:  ");
   cout << endl;

   printStudentVector(failing1, "FAILING:  ");

}




void printStudentVector(vector<Student_info> stdVec, string str) {

   typedef vector<Student_info>::const_iterator student_iter;

   for(student_iter iter = stdVec.begin(); iter < stdVec.end(); ++iter){
      cout << str << (*iter).name << endl;
   }

}

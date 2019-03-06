#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "chapter_code/chapter_code.h"

using std::string;
using std::vector;
using std::list;

using std::cout;
using std::endl;

void printStudentVector(vector<Student_info> stdVec, string str);
void printStudentList(list<Student_info> stdList, string str);

void testExtractFails();


int main() {

   testExtractFails();





}






void testExtractFails() {

   Student_info s1 = { "Floofy", 100, 100, {100, 100, 100} }; 
   Student_info s2 = { "Doot Doot", 0, 0, {60, 50}};
   Student_info s3 = { "Cake", 100, 80, {0}};
   Student_info s4 = { "Floofy-mega", 1000, 1000, {10000}};

   version1 v1;

   vector<Student_info> passing1 = {s1, s2, s3, s4};
   vector<Student_info> failing1 = v1.extract_fails(passing1);

 
   printStudentVector(passing1, "V1 - PASSING:  ");
   cout << endl;

   printStudentVector(failing1, "V1 - FAILING:  ");
   cout << endl << endl;


   /* v2 */

   version2 v2;

   vector<Student_info> passing2 = {s1, s2, s3, s4};
   vector<Student_info> failing2 = v2.extract_fails(passing2);

 
   printStudentVector(passing2, "V2 - PASSING:  ");
   cout << endl;

   printStudentVector(failing2, "V2 - FAILING:  ");
   cout << endl << endl;


   /* v3 */

   version3 v3;

   vector<Student_info> passing3 = {s1, s2, s3, s4};
   vector<Student_info> failing3 = v3.extract_fails(passing3);

 
   printStudentVector(passing3, "V3 - PASSING:  ");
   cout << endl;

   printStudentVector(failing3, "V3 - FAILING:  ");
   cout << endl << endl;

   /* v4 */

   version4 v4;

   list<Student_info> passing4 = {s1, s2, s3, s4};
   list<Student_info> failing4 = v4.extract_fails(passing4);

 
   printStudentList(passing4, "V4 - PASSING:  ");
   cout << endl;

   printStudentList(failing4, "V4 - FAILING:  ");
   cout << endl << endl;




}


void printStudentVector(vector<Student_info> stdVec, string str) {

   typedef vector<Student_info>::const_iterator student_iter;

   for(student_iter iter = stdVec.begin(); iter < stdVec.end(); ++iter){
      cout << str << (*iter).name << endl;
   }

}

void printStudentList(list<Student_info> stdList, string str) {

   typedef list<Student_info>::const_iterator student_iter;

   for(student_iter iter = stdList.begin(); iter != stdList.end(); ++iter){
      cout << str << (*iter).name << endl;
   }

}

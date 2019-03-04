#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

#include "median.h"
#include "student_info.h"
#include "grade.h"

/*

Using our custom header files, the headers, and thus function declarations,
are copied in.


Run "g++ *.cpp" to compile them all together!

*/


using std::cout;
using std::cin;
using std::endl;

using std::string;
using std::vector;
using std::max;
using std::setprecision;

using std::domain_error;

int main() 
{

   //Create a vector Student_info struct objects   
   vector<Student_info> students;

   //Record object we will use for pass-by-reference ("temporary")
   Student_info record;
   string::size_type maxlen = 0;
   
   // read and store all the records, and find the length of the longest name
   //While the istream obj from read() tells us its, ok,
   while(read(cin, record)){
      //After one "read" pass (i.e. one read() exec, or is >> s.name >> s.midterm >> s.final into one read_hw() exec...)

      //Set maxlength to longest name we can find
      maxlen = max(maxlen, record.name.size());

      //Add the record
      students.push_back(record);
   }

   // alphabetize the records
   //Sort them using the compare() function we defined below
   sort(students.begin(), students.end(), compare);

   for(vector<Student_info>::size_type i = 0; i < students.size(); ++i){
      // write the name, padded on the right to maxlen + 1 characters
      cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

      // compute and write the grade
      try {
         double final_grade = grade(students[i]);
         
         //std::streamsize represents a type representing the signed int range of characters passed through stream
         std::streamsize prec = cout.precision(); //getting precision of istream obj, e.g. cout
         cout << setprecision(3) << final_grade << setprecision(prec);
         
      } catch (domain_error e) {
         cout << e.what();
      }
   }

   return 0;
   
}


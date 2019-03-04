#include "student_info.h"
#include "grade.h"

using std::istream;
using std::vector;
using std::cout; using std::endl;
/*
 * Student_info Util
 *
 */

//Bool result is if x is less than y, or 1st less than 2nd; therefore, true values will assume x should come first
bool compare(const Student_info& x, const Student_info& y){
   return x.name < y.name;
}


istream& read(istream& is, Student_info& s){
   // read and store the student's name and midterm and final exam grades
   //Read into Student_info name
   double midterm, final;
   vector<double> homework;

   is >> s.name >> midterm >> final;

   cout << "s.name:  " << s.name << "   midterm:  " <<midterm << "    final:  " << final << endl;

   //Read into Student_info homework vector var
   read_hw(is, homework); // read and store all the student's homework grades
   cout << "FINISHED READING HW" << endl;

   //Calculate grade on end of reading, add to Student_info struct ref
   s.final_grade = grade(midterm, final, homework);   
   cout << "CALCULATED GRADE:   " << s.final_grade << endl << endl << "END OF read()" << endl;

   return is;
}

istream& read_hw(istream& in, vector<double>& hw){
   if(in) {
      // get rid of previous contents
      hw.clear();

      // read homework grades
      double x;
      while (in >> x) {
         hw.push_back(x);
      }

      // clear the stream so that input will work for the next student
      //last line in the pattern, but could we also put this at the end of read...? I guess no point if modular, but... hmm.
      in.clear();

   }
   return in;
}


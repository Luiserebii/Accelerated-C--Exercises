#include "student_info.h"
#include <iostream>

using std::istream;
using std::ostream;
using std::vector;
using std::endl;
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
   //Read into Student_info name, midterm, final vars
   is >> s.name >> s.midterm >> s.final;
   //Read into Student_info homework vector var
   read_hw(is, s.homework); // read and store all the student's homework grades
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
   
/*
int Student_info::constructCount = 0;
int Student_info::copyCount = 0;
int Student_info::assignCount = 0;
int Student_info::destroyCount = 0;
*/
ostream& Student_info::writeCounts(ostream& out) const {
    out << "Construct: " << constructCount << "| "
       << "Copy: "  << copyCount << "| "
       << "Assign: " << assignCount << "| "
       << "Destroy: " << destroyCount << endl;
};


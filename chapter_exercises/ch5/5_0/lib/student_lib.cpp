#include "student_lib.h"
#include <iostream>

using std::string;
using std::vector;

using std::cout;
using std::endl;


bool fgrade(const Student_info& s){
   return grade(s) < 60;
}

double grade(const Student_info& s){
   return grade(s.midterm, s.final, s.homework);
}

double grade(double midterm, double final, vector<double> homework) {

   int hw = 100;

   return 0.2 * midterm + 0.4 * final + 0.4 * hw;
   //we're hardcoding homework to 100 for simplicity

}


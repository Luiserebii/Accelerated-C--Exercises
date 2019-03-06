#ifndef GUARD_student_info
#define GUARD_student_info

/*=============================================================*/


#include <string>
#include <vector>

struct Student_info {

   std::string name;
   double midterm, final;
   std::vector<double> homework;

};

std::vector<Student_info> extract_fails(std::vector<Student_info>& students);
bool fgrade(const Student_info& s);
double grade(const Student_info& s);
double grade(double midterm, double final, std::vector<double> homework);


/*===============================================================*/

#endif

#ifndef GUARD_grade
#define GUARD_grade

/*=============================================*/

#include <vector>
#include "student_info.h"

double grade(const Student_info& s);
double grade(double midterm, double final, const std::vector<double>& hw);
double grade(double midterm, double final, double homework);

/*=============================================*/

#endif

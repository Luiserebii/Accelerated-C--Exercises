#ifndef GUARD_student_info
#define GUARD_student_info

/*================================*/

#include <iostream>
#include <string>
#include <vector>


class Student_info {
    public:
        std::string name;
        double midterm, final;
        std::vector<double> homework;
};


bool compare(const Student_info& x, const Student_info& y);

std::istream& read(std::istream& id, Student_info& s);
std::istream& read_hw(std::istream& in, std::vector<double>& hw);

/*=================================*/

#endif

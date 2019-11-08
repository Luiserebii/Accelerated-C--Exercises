#ifndef GUARD_student_info
#define GUARD_student_info

/*================================*/

#include <iostream>
#include <string>
#include <vector>


class Student_info {
    public:

        Student_info() { ++constructCount; }
        Student_info(const Student_info& s) { ++copyCount; name = s.name; midterm = s.midterm; final = s.final; homework = s.homework; }
        Student_info& operator=(const Student_info& rhs) { ++assignCount; name = rhs.name; midterm = rhs.midterm; final = rhs.final; homework = rhs.homework; return *this; }
        ~Student_info() { ++destroyCount; }


        //Static variables to keep track of these counts
        /*static*/ int constructCount;
        /*static*/ int copyCount;
        /*static*/ int assignCount;
        /*static*/ int destroyCount;

        std::string name;
        double midterm, final;
        std::vector<double> homework;

        //Function to print count vals
        /*static*/ std::ostream& writeCounts(std::ostream& out=std::cout) const;

};


bool compare(const Student_info& x, const Student_info& y);

std::istream& read(std::istream& id, Student_info& s);
std::istream& read_hw(std::istream& in, std::vector<double>& hw);

/*=================================*/

#endif

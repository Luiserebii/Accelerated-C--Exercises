#ifndef GUARD_student_info
#define GUARD_student_info

/*================================*/

#include <iostream>
#include <string>
#include <vector>


class Student_info {
    public:

        //Static variables to keep track of these counts
        static int constructCount;
        static int copyCount;
        static int assignCount;
        static int destroyCount;

        std::string name;
        double midterm, final;
        std::vector<double> homework;

        //Function to print count vals
        static std::ostream& writeCounts(std::ostream& out=std::cout);

};


bool compare(const Student_info& x, const Student_info& y);

std::istream& read(std::istream& id, Student_info& s);
std::istream& read_hw(std::istream& in, std::vector<double>& hw);

/*=================================*/

#endif

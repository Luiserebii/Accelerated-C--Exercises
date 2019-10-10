#include <iostream>

using std::cin;
using std::cout;
using std::endl;

istream& Student_info::read(istream& in) {
    in >> name >> midterm >> final;
    read_hw(in, homework);
    return in;
}

/**
struct Student_info {
    std::string name;
    double midterm, final;
     std::vector<double> homework;
}
*/

/**
struct Student_info {
    std::string name; 
    double midterm, final;
    std::vec
}
*/



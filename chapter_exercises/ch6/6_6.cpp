#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

#include "./6_0/student/student.h"
#include "./6_0/student/lib/median.h"

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::vector;
using std::transform;
using std::back_inserter;

double analysis(const vector<Student_info>& students, double transformer(const Student_info&));

int main() {

}

/**
 * By simply taking a generic function, we thus reduce these three functions into one
 */ 
double analysis(const vector<Student_info>& students, double transformer(const Student_info&)) {
    vector<double> grades;
    //Using the grade function, let's funnel our elements found between the first two iterators and use the back_
    //inserter to add...
    transform(students.begin(), students.end(), back_inserter(grades), transformer);
    return median(grades);
}

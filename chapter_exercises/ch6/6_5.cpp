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

double optimistic_median_analysis(const vector<Student_info>& students);

int main() {

}

double optimistic_median_analysis(const vector<Student_info>& students) {
    vector<double> grades;
    //Using the grade function, let's funnel our elements found between the first two iterators and use the back_
    //inserter to add...
    transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
    return median(grades);
}

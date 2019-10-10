#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "student/student_info.h"

using std::cin;
using std::cout;
using std::endl;

using std::vector;
using std::string;

using std::max;
using std::sort;

int main() {

    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    //Read and store data
    while(record.read(cin)) {
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }

    //Alphabetize the student records
    sort(students.begin(), students.end(), compare);


}


#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

#include "student/student_info.h"

using std::cin;
using std::cout;
using std::endl;

using std::streamsize;
using std::setprecision;

using std::vector;
using std::string;

using std::max;
using std::sort;
using std::domain_error;

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

    //Write names and grades
    for(vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        cout << students[i].name() << string(maxlen + 1 - students[i].name().size(), ' ');
        try {
            double final_grade = students[i].grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                << setprecision(prec) << endl;
        } catch(domain_error e) {
            cout << e.what() << endl;
        }
    }
    return 0;
}


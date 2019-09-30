#include <iostream>
#include <string>
#include <vector>

#include <algorithm>
#include <numeric>

#include "./lib/median.h"
#include "./lib/student_info.h"
#include "./lib/grade.h"
#include "student.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
using std::domain_error;

using std::transform;

using std::accumulate;


int main() {
    
    vector<Student_info> did, didnt;
    Student_info student;
    
    cout << "As a reminder, type in students and their grades via the following format: " << endl
        << "[NAME] [MIDTERM] [FINAL] [HW...]" << endl
        << "NOTE: No homework should be submitted as a 0." << endl;
        

    while(read(cin, student)) {
        did_all_hw(student) ? did.push_back(student) : didnt.push_back(student);
    }

    if(did.empty()) {
        cout << "No student did all the homework!" << endl;
        return 1;
    }

    if(didnt.empty()) {
        cout << "Every student did all the homework!" << endl;
        return 1;
    }

    //Run our analyses here
    write_analysis(cout, "median", median_analysis, did, didnt);
    write_analysis(cout, "average", average_analysis, did, didnt);
    //write_analysis(cout, "median of homework turned in", optimistic_median_analysis, did, didnt);

    return 0;
}

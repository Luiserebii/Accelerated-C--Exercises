#include <iostream>
#include <string>
#include <vector>

#include <algorithm>
#include <numeric>

//#include "./lib/student_lib.h"
#include "./lib/median.h"
#include "./lib/student_info.h"
#include "./lib/grade.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
using std::domain_error;

using std::transform;

using std::accumulate;

bool did_all_hw(const Student_info& s);
double grade_aux(const Student_info& s);
double median_analysis(const vector<Student_info>& students);
void write_analysis(ostream& out, const string& name, double analysis(const vector<Student_info>&), const vector<Student_info>& did, const vector<Student_info>& didnt);
double average(const vector<double>& v);
double average_grade(const Student_info& s);
double average_analysis(const vector<Student_info>& students);
double optimistic_median(const Student_info& s);
bool pgrade(const Student_info& s);
vector<Student_info> extract_fails(vector<Student_info>& students);

int main() {
    
    vector<Student_info> did, didnt;
    Student_info student;
    
    cout << "As a reminder, type in students and their grades via the following format: " << endl
        << "[NAME] [MIDTERM] [FINAL] [HW...]" << endl;

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

bool did_all_hw(const Student_info& s) {
    return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

/**
 * An auxiliary function for covering the possibility of errors being thrown; we can't
 * really have transform do stuff for this
 */
double grade_aux(const Student_info& s) {
    try {
        return grade(s);
    } catch (domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}

double median_analysis(const vector<Student_info>& students) {
    vector<double> grades;
    //Using the grade function, let's funnel our elements found between the first two iterators and use the back_
    //inserter to add...
    transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
    return median(grades);
}

//Using function as parameter!!!
void write_analysis(ostream& out, const string& name,
        double analysis(const vector<Student_info>&),
        const vector<Student_info>& did, 
        const vector<Student_info>& didnt) {

    out << name << ": median(did) = " << analysis(did) <<
        ", median(didnt) = " << analysis(didnt) << endl;
}

double average(const vector<double>& v) {
    return accumulate(v.begin(), v.end(), 0.0);
}

double average_grade(const Student_info& s) {
    return grade(s.midterm, s.final, average(s.homework));
}

double average_analysis(const vector<Student_info>& students) {
    vector<double> grades;

    transform(students.begin(), students.end(), back_inserter(grades), average_grade);
    return median(grades);
}

double optimistic_median(const Student_info& s) {
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

    return nonzero.empty() ? grade(s.midterm, s.final, 0) : grade(s.midterm, s.final, median(nonzero));
}

bool fgrade(const Student_info& s){
       return grade(s) < 60;
}

bool pgrade(const Student_info& s) {
    return !fgrade(s);
}

vector<Student_info> extract_fails(vector<Student_info>& students) {
    vector<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), pgrade);
    vector<Student_info> fail(iter, students.end());
    students.erase(iter, students.end());

    return fail;
}

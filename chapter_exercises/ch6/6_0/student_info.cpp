#include <iostream>

int main() {
    
    vector<Student_info> did, didnt;
    Student_info student;
    
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
    write_analysis(cout, "median of homework turned in", optimistic_median_analysis, did, didnt);

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

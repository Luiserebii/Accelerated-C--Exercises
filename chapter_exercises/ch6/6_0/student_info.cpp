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

}

bool did_all_hw(const Student_info& s) {
    return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}



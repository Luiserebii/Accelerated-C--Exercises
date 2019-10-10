#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::istream;

using std::vector;

int main() {


}

class Student_info {
    
    public: 
        Student_info();
        Student_info(std::istream&);

        std::string name() const { return n; }
        bool valid() const { return !homework.empty(); }
        std::istream& read(std::istream&);
        double grade() const;

    private:
        std::string n;
        double midterm, final;
        std::vector<double> homework;
};

bool compare(const Student_info& x, const Student_info& y);



Student_info::Student_info(): midterm(0), final(0) {

}

Student_info::Student_info(istream& is) { 
    read(is);
}

istream& Student_info::read(istream& in) {
    in >> name >> midterm >> final;
    read_hw(in, homework);
    return in;
}

double Student_info::grade() const {
    return ::grade(midterm, final, homework);
}

bool compare(const Student_info& x, const Student_info& y) {
    return x.name() < y.name();
}

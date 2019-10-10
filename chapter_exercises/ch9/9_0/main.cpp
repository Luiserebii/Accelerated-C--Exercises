#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::istream;

using std::vector;

int main() {


}


class Student_info {
    
    public: 
        double grade() const;
        std::istream& read(std::istream&);

    private:
        std::string name;
        double midterm, final;
        std::vector<double> homework;
}

istream& Student_info::read(istream& in) {
    in >> name >> midterm >> final;
    read_hw(in, homework);
    return in;
}

double Student_info::grade() const {
    return ::grade(midterm, final, homework);
}


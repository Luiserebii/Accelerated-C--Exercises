#include <iostream>
#include <vector>
#include <string>

#include "grade.h"

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
istream& read_hw(istream& in, vector<double>& hw);


Student_info::Student_info(): midterm(0), final(0) {

}

Student_info::Student_info(istream& is) { 
    read(is);
}

istream& Student_info::read(istream& in) {
    in >> n >> midterm >> final;
    read_hw(in, homework);
    return in;
}

double Student_info::grade() const {
    return ::grade(midterm, final, homework);
}

bool compare(const Student_info& x, const Student_info& y) {
    return x.name() < y.name();
}

istream& read_hw(istream& in, vector<double>& hw){
   if(in) {
      // get rid of previous contents
      hw.clear();

      // read homework grades
      double x;
      while (in >> x) {
         hw.push_back(x);
      }

      // clear the stream so that input will work for the next student
      //last line in the pattern, but could we also put this at the end of read...? I guess no point if modular, but... hmm.
      in.clear();

   }
   return in;
}


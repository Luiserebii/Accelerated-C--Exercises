#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>


using std::cout;
using std::cin;
using std::endl;

using std::string;
using std::vector;
using std::max;
using std::setprecision;

using std::domain_error;
struct Student_info {
   string name;
   double midterm, final;
   vector<double> homework;
};


std::istream& read(std::istream& id, Student_info& s);
std::istream& read_hw(std::istream& in, vector<double>& hw);

double grade(const Student_info& s);
double grade(double midterm, double final, const vector<double>& hw);
double grade(double midterm, double final, double homework);

bool compare(const Student_info& x, const Student_info& y);
double median(vector<double> vec);

int main() 
{

   //Create a vector Student_info struct objects   
   vector<Student_info> students;

   //Record object we will use for pass-by-reference ("temporary")
   Student_info record;
   string::size_type maxlen = 0;
   
   // read and store all the records, and find the length of the longest name
   //While the istream obj from read() tells us its, ok,
   while(read(cin, record)){
      //After one "read" pass (i.e. one read() exec, or is >> s.name >> s.midterm >> s.final into one read_hw() exec...)

      //Set maxlength to longest name we can find
      maxlen = max(maxlen, record.name.size());

      //Add the record
      students.push_back(record);
   }

   // alphabetize the records
   sort(students.begin(), students.end(), compare);

   for(vector<Student_info>::size_type i = 0; i < students.size(); ++i){
      // write the name, padded on the right to maxlen + 1 characters
      cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

      // compute and write the grade
      try {
         double final_grade = grade(students[i]);
         std::streamsize prec = cout.precision(); //getting precision of istream obj
         cout << setprecision(3) << final_grade << setprecision(prec);
         
      } catch (domain_error e) {
         cout << e.what();
      }
   }

   return 0;
   
}


std::istream& read(std::istream& is, Student_info& s){
   // read and store the student's name and midterm and final exam grades
   is >> s.name >> s.midterm >> s.final;

   read_hw(is, s.homework); // read and store all the student's homework grades
   return is;
}

std::istream& read_hw(std::istream& in, vector<double>& hw){
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


double grade(const Student_info& s){
   return grade(s.midterm, s.final, s.homework);
}

double grade(double midterm, double final, const vector<double>& hw){
   if (hw.size() == 0){
      throw domain_error("student has done no homework");
   }
   return grade(midterm, final, median(hw));
}

double grade(double midterm, double final, double homework)
{
   return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

bool compare(const Student_info& x, const Student_info& y){
   return x.name < y.name;
}

double median(vector<double> vec){
   typedef vector<double>::size_type vec_sz;

   vec_sz size = vec.size();
   if (size == 0) {
      throw domain_error("median of an empty vector");
   }
 
   sort(vec.begin(), vec.end());

   vec_sz mid = size/2;
   
   return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];

}



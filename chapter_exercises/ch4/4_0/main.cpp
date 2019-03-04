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


double grade(const Student_info& s);
double grade(double midterm, double final, const vector<double>& hw);
double grade(double midterm, double final, double homework);


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
   //Sort them using the compare() function we defined below
   sort(students.begin(), students.end(), compare);

   for(vector<Student_info>::size_type i = 0; i < students.size(); ++i){
      // write the name, padded on the right to maxlen + 1 characters
      cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

      // compute and write the grade
      try {
         double final_grade = grade(students[i]);
         
         //std::streamsize represents a type representing the signed int range of characters passed through stream
         std::streamsize prec = cout.precision(); //getting precision of istream obj, e.g. cout
         cout << setprecision(3) << final_grade << setprecision(prec);
         
      } catch (domain_error e) {
         cout << e.what();
      }
   }

   return 0;
   
}


//grade the struct
double grade(const Student_info& s){
   return grade(s.midterm, s.final, s.homework);
}

//grade the two doubles and vector passed
double grade(double midterm, double final, const vector<double>& hw){
   if (hw.size() == 0){
      throw domain_error("student has done no homework");
   }
   return grade(midterm, final, median(hw));
}

//grade the three doubles passed
double grade(double midterm, double final, double homework)
{
   return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}




#include <iostream>
#include <string>
#include <vector>



using std::string;
using std::vector;


struct Student_info {

   string name;
   double midterm, final;
   vector<double> homework;

};

vector<Student_info> extract_fails(vector<Student_info>& students);
bool fgrade(const Student_info& s);
double grade(const Student_info& s);
double grade(double midterm, double final, vector<double> homework);



int main() {

   Student_info s1 = { "Floofy", 100, 100, {100, 100, 100} }; 

}


vector<Student_info> extract_fails(vector<Student_info>& students){

   vector<Student_info> pass, fail;
   
   for(vector<Student_info>::size_type i = 0; i < students.size(); ++i){

      if(fgrade(students[i]))
         fail.push_back(students[i]);
      else
         pass.push_back(students[i]);      
      
   }

   students = pass;
   return fail;
   
}





bool fgrade(const Student_info& s){
   return grade(s) < 60;
}

double grade(const Student_info& s){
   return grade(s.midterm, s.final, s.homework);
}

double grade(double midterm, double final, vector<double> homework) {

   int hw = 100;

   return 0.2 * midterm + 0.4 * final + 0.4 * hw;
   //we're hardcoding homework to 100 for simplicity

}


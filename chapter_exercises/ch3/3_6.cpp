/*

The average-grade computation in §3.1/36 might divide by zero if the student didn't enter any grades. Division by zero is undefined in C++, which means that the implementation is permitted to do anything it likes. What does your C++ implementation do in this case? Rewrite the program so that its behavior does not depend on how the implementation treats division by zero.



Seems if nothing is entered, done by forcing EOF (CTRL+D on Ubuntu Linux 16.04) it simply gives "-nan". If simply 0 is entered, it just yields 0. To prevent this depending on implementation, let's edit it as so:

*/

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using std::cin;           using std::setprecision;
using std::cout;          using std::string;
using std::endl;          using std::streamsize;

int main()
{
   // ask for an read the student's name
   cout << "Please enter your first name: ";
   string name;
   cin >> name;
   cout << "Hello, " << name << "!" << endl;

   // ask for and read the midterm and final grades
   cout << "Please enter your midterm and final exam grades: ";
   double midterm, final;
   cin >> midterm >> final;

   // ask for the homework grades
   cout << "Enter all your homework grades, "
           "followed by end-of-file: ";

   // the number and sum of grades read so far
   int count = 0; 
   double sum = 0;
   
   // a variable into which to read
   double x;

   // invariant:
   // we have read count grades so far, and
   // sum is the sum of the first count grades
   while (cin >> x) {
      ++count;
      sum += x;
   }
 
   //Addition is here; apply conditional logic on homeworkGrade, and assume that no homework was simply completed; the homework grade for the student is thus 0. This keeps the result implementation-agnostic.
   double homeworkGrade;
   count != 0 ? homeworkGrade = sum / count : homeworkGrade = 0;

   // write the result
   streamsize prec = cout.precision();
   cout << "Your final grade is " << setprecision(3)
        << 0.2 * midterm + 0.4 * final + 0.4 * homeworkGrade
        << setprecision(prec) << endl;
  
   return 0;

}




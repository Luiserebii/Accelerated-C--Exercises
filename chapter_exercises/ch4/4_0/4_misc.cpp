#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::streamsize;

double grade(double midterm, double final, double homework);


int main() {
   streamsize prec = cout.precision(); 
   cout << "Your final grade is " << setprecision(3) << grade(10.12, 30.12, 100) << setprecision(prec) << endl;
   
   

   
}


double grade(double midterm, double final, double homework)
{
   return 0.2 * midterm + 0.4 * final + 0.4 * homework; 
}



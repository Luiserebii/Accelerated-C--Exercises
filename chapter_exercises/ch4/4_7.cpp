/*

Write a program to calculate the average of the numbers stored in 
a vector<double>

*/


#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;

using std::string;
using std::vector;

double average(const vector<double> &nums);

int main() {

   //To use initializer lists, pass the flag: "-std=c++0x" in compilation
   vector<double> nums = { 1, 10, 9, 8 };
   cout << "NUMS:    1 10 9 8" << endl;
   cout << "AVERAGE:    " << average(nums) << endl;

}



double average(const vector<double> &nums){
   
   typedef vector<double>::size_type vec_size;
   vec_size count = nums.size();

   cout << "SIZE:   " << count << endl;

   double sum = 0;
   for(vec_size i = 0; i < count; i++){
      sum += nums[i];
   }
   cout << "SUM:   " << sum << endl;
   
   return sum / count;
   
}

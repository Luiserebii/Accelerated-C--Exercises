#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

#include "median.h"

using std::vector;
using std::domain_error;

double median(vector<double> vec){

   //For simplicity, define the vector<double>::size_type as vec_sz
   typedef vector<double>::size_type vec_sz;

   vec_sz size = vec.size();
   if (size == 0) {
      throw domain_error("median of an empty vector");
   }
 
   sort(vec.begin(), vec.end());

   vec_sz mid = size/2;
   
   return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];

}


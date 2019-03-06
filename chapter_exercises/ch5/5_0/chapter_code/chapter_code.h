#ifndef GUARD_chapter_code
#define GUARD_chapter_code

/*================================================*/

#include <vector>
#include <list>
#include "../lib/student_lib.h"


std::vector<std::string> split(const std::string& s);

std::string::size_type width(const std::vector<std::string>& v);
std::vector<std::string> frame(const std::vector<std::string>& v);

std::vector<std::string> vcat(const std::vector<std::string>& top, const std::vector<std::string>& bottom);
std::vector<std::string> hcat(const std::vector<std::string>& left, const std::vector<std::string>& right);


class version1 {

   public:

      std::vector<Student_info> extract_fails(std::vector<Student_info>& students){

         std::vector<Student_info> pass, fail;
         for(std::vector<Student_info>::size_type i = 0; i < students.size(); ++i){

            if(fgrade(students[i]))
               fail.push_back(students[i]);
            else
               pass.push_back(students[i]);      
      
         }

         students = pass;
         return fail;
   
      }


};


class version2 {

   public:

      std::vector<Student_info> extract_fails(std::vector<Student_info>& students){

         std::vector<Student_info> fail;
         std::vector<Student_info>::size_type i = 0;


         while(i != students.size()) {
            if(fgrade(students[i])) {
               fail.push_back(students[i]);
               students.erase(students.begin() + i);
            } else
               ++i;

         }


         return fail;
    
      }


};

class version3 {

   public:

      std::vector<Student_info> extract_fails(std::vector<Student_info>& students){

         std::vector<Student_info> fail;
         std::vector<Student_info>::iterator iter = students.begin();


         while(iter != students.end()) {
            if(fgrade(*iter)) {
               fail.push_back(*iter);
               iter = students.erase(iter);
            } else
               ++iter;
         }


         return fail;
    
      }


};

class version4 {

   public:

      std::list<Student_info> extract_fails(std::list<Student_info>& students){

         std::list<Student_info> fail;
         std::list<Student_info>::iterator iter = students.begin();


         while(iter != students.end()) {
            if(fgrade(*iter)) {
               fail.push_back(*iter);
               iter = students.erase(iter);
            } else
               ++iter;
         }


         return fail;

      }


};









/*=================================================*/

#endif

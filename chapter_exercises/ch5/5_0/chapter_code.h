#ifndef GUARD_chapter_code
#define GUARD_chapter_code

/*================================================*/

#include <vector>
#include "lib/student_lib.h"



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











/*=================================================*/

#endif

#ifndef GUARD_student_6_h
#define GUARD_student_6_h

#include <iostream>
#include <string>
#include <vector>

//#include "./lib/median.h"
#include "./lib/student_info.h"
//#include "./lib/grade.h"


bool did_all_hw(const Student_info& s);
double grade_aux(const Student_info& s);
double median_analysis(const std::vector<Student_info>& students);
void write_analysis(std::ostream& out, const std::string& name, double analysis(const std::vector<Student_info>&), const std::vector<Student_info>& did, const std::vector<Student_info>& didnt);
double average(const std::vector<double>& v);
double average_grade(const Student_info& s);
double average_analysis(const std::vector<Student_info>& students);
double optimistic_median(const Student_info& s);
bool pgrade(const Student_info& s);
std::vector<Student_info> extract_fails(std::vector<Student_info>& students);
template <class T>
double analysis(const std::vector<Student_info>& students, T predicate);

#endif

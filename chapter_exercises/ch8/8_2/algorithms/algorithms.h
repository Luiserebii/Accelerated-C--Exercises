#ifndef GUARD_ALGORITHMS_h
#define GUARD_ALGORITHMS_h

#include <iostream>
#include <vector>

template <class InputIterator>
bool equal(InputIterator begin, InputIterator end, InputIterator begin2);

template <class InputIterator, class T>
bool find(InputIterator begin, InputIterator end, T val);

template <class T>
std::istream& readVector(std::vector<T>& v, std::istream& in);

template <class T> 
std::ostream& writeVector(const std::vector<T>& v, std::ostream& out);

#endif

#ifndef GUARD_ALGORITHMS_h
#define GUARD_ALGORITHMS_h

#include <iostream>
#include <vector>

template <class InputIterator>
bool equal(InputIterator begin, InputIterator end, InputIterator begin2);

template <class InputIterator, class T>
bool find(InputIterator begin, InputIterator end, T val);

template <class InputIterator, class OutputIterator>
void copy(InputIterator begin, InputIterator end, OutputIterator destination);

template <class T>
std::istream& readVector(std::vector<T>& v, std::istream& in);

template <class T> 
std::ostream& writeVector(const std::vector<T>& v, std::ostream& out);

/**
 * How to compile with templates?
 *
 * This is an issue that the book had warned me ahead of time; the definition of templates
 * are needed at link time, and typically, this is provided within the header. 
 *
 * At the moment, I am providing the implementation in a seperate header file. It is still
 * capped off with ".h" because I don't feel like trying to see how to get vim to recognize
 * ".tpp" files as valid C++ for highlighting/editing convenience, and also, I'm not entirely
 * sure what the right way to do this is.
 *
 * I am also using: https://stackoverflow.com/questions/495021/why-can-templates-only-be
 * -implemented-in-the-header-file as inspiration.
 *
 * Something else, too: If I'm including this file into the header file, shouldn't the
 * implementation get its own header guard and fully qualified names? For the moment, I am going
 * to just give it a header guard, but qualified names... the only way would be to constantly
 * upkeep a search-and-replace, you know, it can be inconvenient to do this for every single line. 
 *
 * Would that be the only way? Keeping this blob here for reference.
 *
 **/

#include "algorithms-implementation.h"

#endif

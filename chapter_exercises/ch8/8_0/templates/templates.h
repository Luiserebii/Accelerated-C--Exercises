#ifndef GUARD_TEMPLATES_h
#define GUARD_TEMPLATES_h

#include <vector>
#include <string>



template <class T>
T median(std::vector<T> v);

template <class In, class X> In find(In begin, In end, const X& x);

template <class In, class Out>
Out copy(In begin, In end, Out dest);

template <class For, class X>
void replace(For begin, For end, const X& x, const X& y);

template <class Bi> void reverse(Bi begin, Bi end);

template <class Ran, class X>
bool binary_search(Ran begin, Ran end, const X& x);

template <class Out>
void split(const std::string& str, Out os);

bool space(char c);
bool not_space(char c);



#endif

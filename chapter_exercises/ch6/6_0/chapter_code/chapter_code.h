#ifndef GUARD_CH_6_CODE_h
#define GUARD_CH_6_CODE_h

#include <string>
#include <vector>

bool space(char c);
bool not_space(char c);
std::vector<std::string> split(const std::string& str);
bool is_palindrome(const std::string& s);
std::vector<std::string> find_urls(const std::string& s);
std::string::const_iterator url_end(std::string::const_iterator b, std::string::const_iterator e);
bool not_url_char(char c);
std::string::const_iterator url_beg(std::string::const_iterator b, std::string::const_iterator e);

#endif

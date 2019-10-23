#ifndef GUARD_string_list_h
#define GUARD_string_list_h

#include <string>

class StringList {

    private:
        //Array of strings
        string* a;
        size_t size;
        
        void expand(size_t size);

    public:
        StringList();
        void push_back(std::string s);

        string* getStringArr();
};

#endif

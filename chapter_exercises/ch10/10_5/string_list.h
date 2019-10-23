#ifndef GUARD_string_list_h
#define GUARD_string_list_h

#include <string>

class StringList {

    private:
        //Array of strings
        string* a;
        
        void increaseArr();

    public:
        StringList();
        void push_back(std::string s);

        string* getStringArr();
};

#endif

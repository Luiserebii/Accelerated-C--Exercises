#ifndef GUARD_string_list_h
#define GUARD_string_list_h

#include <string>

class StringList {

    private:
        //Array of std::strings
        std::string* a;
        size_t size;
        
        void expand(size_t size);

    public:
        StringList();
        void push_back(std::string s);

        std::string* getStringArr();
        std::string* begin();
    
        typedef std::string* iterator;
};

#endif

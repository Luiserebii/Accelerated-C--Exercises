#ifndef GUARD_string_list_h
#define GUARD_string_list_h

#include "node/node.h"
#include <string>

class StringList {

    private:
        Node head;

    public:
        StringList();
        void push_back(std::string s);

        Node getHead();
};

#endif

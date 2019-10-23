#ifndef GUARD_node_h
#define GUARD_node_h

#include <string>

class Node {
    public:
        Node();
        Node(std::string s);
        Node(std::string s, Node* n);

        //We're just going to keep this public for convenience
        std::string str;
        Node* next;
};

#endif

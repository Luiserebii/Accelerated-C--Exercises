#include "node.h"
#include <string>

using std::string;

Node::Node() {
    next = NULL;    
}

Node::Node(string s) {
    str = s;
    next = NULL;
}

Node::Node(string s, Node* n) {
    str = s;
    next = n;
}

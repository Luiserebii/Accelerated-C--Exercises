#include "string_list.h"
#include "node/node.h"
#include <string>

using std::string;

StringList::StringList() {
}

void StringList::push_back(string s) {
    Node* n = &head;
    if(n->str == ""){
        n->str = s;
    } else {
        while(n->next != NULL) {
            n = n->next;
        }
        //Allocate memory for new Node
        Node* a = new Node(s);
        //Link last node to newly added one
        n->next = a;
    }
}

Node StringList::getHead() {
    return head;
}

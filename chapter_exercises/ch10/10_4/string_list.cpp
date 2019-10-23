#include <string>

using std::string;

class Node {
    public:
        Node();
        Node(string s);
        Node(string s, Node* n);

        string str;
        Node* next;
};

class StringList {

    private:
        Node head;

    public:
        StringList();
        void push_back(string s);
        

};

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



StringList::StringList() {
}

void StringList::push_back(string s) {
    Node* n = &head;
    while(n->next != NULL) {
        n = n->next;
    }
    //Allocate memory for new Node
    Node* a = new Node(s);
    //Link last node to newly added one
    n->next = a;
}

int main() {

}


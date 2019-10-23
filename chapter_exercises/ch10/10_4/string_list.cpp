#include <string>

using std::string;

class StringList {

    private:
        Node head;

    public:
        StringList();
        void push_back(string s);
        

};

class Node {
    public:
        Node();
        Node(string s);
        Node(string s, Node* n);

        string str;
        Node* next;
};

Node::Node() {
    Node* next = NULL;    
}

Node::Node(string s) {
    str = s;
    Node* next = NULL;
}

Node::Node(string s, Node* n) {
    str = s;
    next = n;
}

StringList::StringList() {
}

void StringList::push_back(string s) {
    Node n = head;
    while(n.next != NULL) {
        n = *next;
    }
    Node a = new Node();
    a.s = 

}

int main() {

}


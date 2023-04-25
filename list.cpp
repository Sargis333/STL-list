#include <iostream>
using namespace std;
class Node {
    int data;
    Node *next;
    public:
        Node(int i):data(i),next(NULL) {}
        inline void setNext(Node *node) {
            this->next = node;
        }
        inline int Data() {
            return this->data;
        }
        inline Node * Next() {
            return this->next;
        }
};
class List {
    Node *Head;
    public:
        List():Head(NULL) {}
        void push_front(int i);
        void push_back(int i);
        void print();
};

void List::push_front(int i) {
    Node *node = new Node(i);
    node->setNext(Head);
    Head = node;
}

void List::push_back(int i) {
    Node *node = new Node(i);
    if(Head == NULL) {
        Head = node;
        return;
    }
    Node *curr = Head;
    while(curr && curr->Next()) {
        curr = curr->Next();
    }
    curr->setNext(node);
}

void List::print() {
    Node *curr = Head;
    while(curr) {
        cout << curr->Data();
        cout << " ";
        curr = curr->Next();
    }
}
int main() {
    List list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.print();
}
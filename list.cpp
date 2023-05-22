#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != NULL) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    
    void push_front(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    
    void push_back(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    
    void deleteNode(int value) {
        if (head == NULL) {
            return;
        }

        if (head->data == value) {
            head = head->next;
            return;
        }

        Node* current = head;
        while (current->next != NULL && current->next->data != value) {
            current = current->next;
        }

        if (current->next != NULL) {
            current->next = current->next->next;
        }
    }

    
    void sort() {
        if (head == NULL) {
            return;
        }

        Node* i = head;
        while (i->next != NULL) {
            Node* j = i->next;
            Node* minNode = i;

            while (j != NULL) {
                if (j->data < minNode->data) {
                    minNode = j;
                }
                j = j->next;
            }

            if (minNode != i) {
                int temp = i->data;
                i->data = minNode->data;
                minNode->data = temp;
            }

            i = i->next;
        }
    }

    
    void printList() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.push_front(5);
    list.push_back(10);
    list.push_front(3);
    list.push_back(15);
    list.printList();
    list.sort();
    list.printList();
    list.deleteNode(5);
    list.printList();
    return 0;
}

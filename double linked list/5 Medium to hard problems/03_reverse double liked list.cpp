#include <iostream>
#include <vector>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;

    ~node() {}
};

class LinkedList {
private:
    node* head = nullptr;
    node* tail = nullptr;
    int length = 0;

public:
    void insertNode(int value) {
        node* new_node = new node;
        new_node->data = value;
        if (head == nullptr) {
            head = tail = new_node;
            new_node->next = nullptr;
        }
        else {
            tail->next = new_node;
            new_node->next = nullptr;
            new_node->prev = tail;
            tail = new_node;
        }
        length++;
    }
    
void link(node* first, node* second) {
    if (first) {
         first->next = second;
    }
    if (second) {
         second->prev = first;
    }
}

void reverseDLL() {
    vector <int> myVector;
    node* temp = head;
    while (temp) {
        myVector.push_back(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp) {
        temp->data = myVector.back();
        myVector.pop_back();
        temp = temp->next;
    }
}

void display() {
    node* current = head;
    if (current == nullptr) {
        cout << "Linked List is empty!" << endl;
    }
    else {
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}

};

int main() {
LinkedList list;
list.insertNode(1);
list.insertNode(2);
list.insertNode(3);
list.insertNode(4);
list.insertNode(5);
list.insertNode(6);
list.display();
list.reverseDLL();
list.display();

return 0;
}
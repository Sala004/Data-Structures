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

    void mergeLists(LinkedList &other) {
    node* prev = nullptr;
    node* curr = head; 
    node* scurr = other.head; 
    while (curr) { 
        while (scurr) { 
            if (scurr->data < head->data) {
                node* temp = scurr->next; 
                link(scurr, head); 
                head = prev = scurr; 
                scurr = temp;
            }

            else if (scurr->data < curr->data) {
                node* temp = scurr->next; 
                link(prev, scurr); 
                prev = prev->next;
                link(scurr, curr); 
                scurr = temp; 
            }

            else {
                break;
            }
        }
        prev = curr;
        curr = curr->next;
    }
    
    //if the second list still has elements
    while(scurr){
        link(tail, scurr);
        tail = scurr;
        scurr = scurr->next;
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
list.insertNode(10);
list.insertNode(20);
list.insertNode(30);
list.insertNode(40);
list.insertNode(50);
LinkedList list2;
list2.insertNode(15);
list2.insertNode(17);
list2.insertNode(22);
list2.insertNode(24);
list2.insertNode(35);
list.display();
list.mergeLists(list2);
list.display();

return 0;
}
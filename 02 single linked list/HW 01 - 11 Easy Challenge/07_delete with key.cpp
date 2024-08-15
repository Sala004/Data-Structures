#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

class LinkedList {
private:
    node* head {};
    node* tail {};
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
            tail = new_node;
        }
        length++;
    }

    void deleteWithKey(int value) {
        for (node* current = head; current; current = current->next) {
            if (current->next->data == value) {
                node* toDelete = current->next;
                bool isTail = toDelete == tail;
                current->next = current->next->next;
                delete toDelete;
                if (isTail) {
                    tail = current;
                }
                return;
            }
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
    list.display();
    list.deleteWithKey(40);
    list.insertNode(80);
    list.display();
    return 0;
}
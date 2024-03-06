#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;

    ~node() {}
};

class LinkedList {
private:
    node* head;
    node* tail;
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

    void deleteNextNode(node* nodee) {
        node* toDelete = nodee->next;
        bool isTail = toDelete == tail;
        nodee->next = nodee->next->next;

        delete toDelete;

        if (isTail) {
            tail = nodee;
        }
    }

    void deleteDuplicates() {
        if (!head || !head->next) {
            return;
        }
        node* temp = head;
        node* current = head->next;

        for (node* curr1 = head; curr1; curr1 = curr1 = curr1->next) {
            for (node* curr2 = curr1->next, *prev = curr1; curr2;) {
                if (curr1->data == curr2->data) {
                    deleteNextNode(prev);
                    curr2 = prev->next;
                }
                else {
                    prev = curr2, curr2 = curr2->next;
                }
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
    list.insertNode(1);
    list.insertNode(1);
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(3);
    list.display();
    list.deleteDuplicates();
    list.display();
    return 0;
}
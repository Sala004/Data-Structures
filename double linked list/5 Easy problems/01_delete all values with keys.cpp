#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;

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
    
    void deleteFront() {
        node* toDelete = head;
        head = head->next;
        delete toDelete;
        length--;
    }

    void deleteNextNode(node* preCurr) {
        node* toDelete = preCurr->next;
        bool isTail = toDelete == tail;
        node* afterCurr = preCurr->next->next;
        link(preCurr, afterCurr);
        delete toDelete;

        if (isTail) {
            tail = preCurr;
        }
        length--;
    }

    void deleteWithKey(int value) {
        if (head->data == value) {
            deleteFront();
        }

        node* toDelete = nullptr;

        for (node* curr = head, *prev = nullptr; curr;) {
            if (curr->data == value) {
                deleteNextNode(prev);
                if (!prev->next) {
                    break;
                }
                else {
                    curr = prev->next->next;
                    prev = prev->next;
                }
            }
            else {
                prev = curr;
                curr = curr->next;
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
    list.insertNode(5);
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(5);
    list.insertNode(1);
    list.insertNode(5);
    list.insertNode(2);
    list.display();
    list.deleteWithKey(5);
    list.display();
    return 0;
}
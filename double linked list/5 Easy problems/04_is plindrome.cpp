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

    bool isPlindrome() {
        int count = length / 2;
        for (node* left = head, *right = tail; count; count--) {
            if (left->data == right->data) {
                right = right->prev;
                left = left->next;
            }
            else {
                return false;
                break;
            }
        }
        return true;
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
    list.insertNode(3);
    list.insertNode(1);
    list.display();
    cout << list.isPlindrome();
    return 0;
}
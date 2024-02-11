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

    void deleteNextNode(node* nod) {
        node* toDelete = nod->next;
        bool isTail = toDelete == tail;

        nod->next = nod->next->next;

        delete toDelete;

        if (isTail) {
            tail = nod;
        }
    }

    void deleteEvenPositions() {
        if (length <= 1) {
            return;
        }
        node* prev = head;
        for (node* curr = head->next; curr;) {
            deleteNextNode(prev); 
            if (!prev->next) {
                break;
            }
            else {
                curr = prev->next->next;
                prev = prev->next; 
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
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);
    list.insertNode(5);
    list.insertNode(6);
    list.display();
    list.deleteEvenPositions();
    list.display();
    return 0;
}
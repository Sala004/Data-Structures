#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;

    ~node() {}
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

    void swapHeadAndTail() {
        if (!head || !head->next) {
            return;
        }
        else if (length == 2) {
            //swap
            node* temp = head;
            head = tail;
            tail = temp;
            
            head->next = tail;
            tail->next = nullptr;
            return;
        }

        node* prev = head;
        while (prev->next != tail) {
            prev = prev->next;
        }

        //swap head and tail
        node* temp = head;
        head = tail;
        tail = temp;

        head->next = temp->next;
        prev->next = tail;
        tail->next = nullptr;
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
    list.insertNode(4);
    list.insertNode(3);
    list.insertNode(5);
    list.display();
    list.swapHeadAndTail();
    list.display();
    return 0;
}

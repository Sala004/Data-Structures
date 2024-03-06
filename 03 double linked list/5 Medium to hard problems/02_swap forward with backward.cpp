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
    
void swapForwardWithBackward(int k) {
    int count = 1;
    node* left = head;
    node* right = tail;
    while (count < k) {
        ++count;
        left = left->next;
        right = right->prev;
    }

    if (right == left) {
        return; //same node
    }
    if (k > length / 2) {
        swap(left, right);
    }

    node* prvleft = left->prev;
    node* prvright = right->next;
    
    if (k == 1) {
        swapTailAndHead();
    }
    else if (length / 2 == k) {
        link(prvleft, right);
        link(right, left);
        link(left, prvright);
    }
    else {
        node* nxright = right->prev;
        link(prvleft, right);
        link(right, left->next);
        link(nxright, left);
        link(left, prvright);
    }
}

void swapTailAndHead() {
    if (!head || !head->next) {
        return;
    }
    else if (length == 2) {
        link(tail, head);
        head->next = tail->prev = nullptr;
        swap(head, tail);
    }
    else {
        link(tail->prev, head);
        link(tail, head->next);
        head->next = tail->prev = nullptr;
        swap(head, tail);
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
list.insertNode(7);
list.insertNode(8);
list.display();
list.swapForwardWithBackward(6);
list.display();

return 0;
}
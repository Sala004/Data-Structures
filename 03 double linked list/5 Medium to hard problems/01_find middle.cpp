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

    //using double liked list
    int findMiddleII() {
    if (head == tail || head->next == tail) {
        return -1;
    }
    node* left = head;
    node* right = tail;
    while (left) {
            //they are equal
            if (left->data == right->data) {
                return left->data;
            }
            //they are neighbours (even)
            else if(left->data == right->prev->data){
                return right->data;
            }
            else {
                left = left->next;
                right = right->prev;
            }
    }
    return -1; //not found
}

    //using single liked list
    int findMiddle() {
        node* slow = head;
        node* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data; 
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
    list.display();
    cout << list.findMiddle();
    return 0;
}
#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

class LinkedList{
private:
    node* head = nullptr;
    node* tail = nullptr;
    int length = 0;

public:
    void insertAtEnd(int value) {
        node* newNode;
        newNode = new node;
        newNode->data = value;
        if(head == NULL) {
            head = tail = newNode;
            newNode->next = NULL;
        }
        else{
            tail->next = newNode;
            newNode->next = NULL;
            tail = newNode;
        }
        length++;
    }

    ~LinkedList() {
        node* current = head;
        node* prev = nullptr;
        while(current){
            prev = current;
            current = current->next;
            delete prev;
        }
        head = nullptr;
        cout << "Linked List has been destroyed!";
    }
};
int main() {
    LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);

    return 0;
}
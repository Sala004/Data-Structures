#include <iostream>
#include <cassert>
using namespace std;

struct node {
    int data;
    node *next;
};

class LinkedList{
private:
    node *head = nullptr;
    node *tail = nullptr;
    int length = 0;
public:
    //Problem 2
    void insertAtFront(int value){
        node* newNode;
        newNode = new node;
        newNode->data = value;
        if(head == NULL){
            head = tail = newNode;
            newNode->next = nullptr;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void display(){
        node* current;
        for(current = head; current; current = current->next){
            cout << current->data << " ";
        }
    }

};

int main() {
    LinkedList list;
    list.insertAtFront(3);
    list.insertAtFront(2);
    list.insertAtFront(1);
    list.display();
    return 0;
}
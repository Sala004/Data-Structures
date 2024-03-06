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

    //Problem 3
    void DeleteFront(){
        if(head->next == NULL){
            head = NULL;
        }
        else
        {
            node* current = head->next;
            delete head;
            head = current;
        }
    }

    void display(){
        node* current;
        for(current = head; current; current = current->next){
            cout << current->data << " ";
        }
        cout << endl;
    }

};

int main() {
    LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.display();
    list.DeleteFront();
    list.DeleteFront();
    list.display();
    return 0;
}
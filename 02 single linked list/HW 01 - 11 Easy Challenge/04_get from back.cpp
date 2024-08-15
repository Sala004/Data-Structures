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

    //Problem 4
    node* getFromBack(int pos){
        assert(pos <= length);
        node *current = head;
        int count = length - pos;
        for(int i = 0; current; current = current->next, i++)
        {
            if(i == count){
                return current;
            }
        }
        return nullptr;
    }

    void display(){
        node* current;
        for(current = head; current; current = current->next){
            cout << current->data << " ";
        }
        cout << endl;
    }
};

int main(){
    LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    cout << list.getFromBack(1)->data << endl;
    cout << list.getFromBack(2)->data << endl;
    cout << list.getFromBack(3)->data << endl;
    cout << list.getFromBack(4)->data << endl;
    return 0;
}
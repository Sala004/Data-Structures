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
public:
    void addElement(int value){
        node* newNode = new node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    node* getTail() {
        node* current = head;
        while(current->next){
            current = current->next;
        }
        return current;
    }

    void print() {
        node* current = head;
        while(current) {
            cout << current->data << " ";
            current = current->next;
        }
        
        cout << endl;
    }

};

int main() {
    LinkedList list;
    list.addElement(1);
    list.addElement(2);
    list.addElement(3);
    list.addElement(4);
    list.print(); // 4 3 2 1
    cout << list.getTail()->data << endl; //1
    return 0;
}
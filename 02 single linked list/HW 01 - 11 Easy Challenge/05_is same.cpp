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
    bool isSame(LinkedList &other)
    {
        if(other.length == length){
            node *current1 = head;
            node *current2 = other.head;
            while(current1 && current2)
            {
                if(current1->data != current2->data){
                    return false;
                }
                current1 = current1->next;
                current2 = current2->next;
            }
            return true;
        }
        return false;
    }

    void display(){
        node* current;
        for(current = head; current; current = current->next){
            cout << current->data << " ";
        }
    }
};

int main() {
    LinkedList list1;
    LinkedList list2;
    cout << list1.isSame(list2) << endl; //1
    list1.insertAtEnd(6);
    list1.insertAtEnd(10);
    list2.insertAtEnd(6);
    cout << list1.isSame(list2) << endl; //0
    list2.insertAtEnd(10);
    cout << list1.isSame(list2) << endl; //1
    return 0;
}
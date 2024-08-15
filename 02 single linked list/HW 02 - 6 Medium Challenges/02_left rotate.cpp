#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

class LinkedList { 
private:
    node* head {};
    node* tail {};
    int length = 0;

public: 
    void insertNode(int value){
    node* new_node;
    new_node = new node;
    new_node->data = value;
    if(head == NULL)
    {
        head = tail = new_node;
        new_node->next = NULL;
    }
    else
    {
        tail->next = new_node;
        new_node->next = NULL;
        tail = new_node;
    }
    length++;
}

    void leftRotate(int k) {
        if(length <= 1 || k % length == 0){
            return;
        }
        k %= length; //remove useless cycles
        while(k--) {
            node* temp = head; 
            head = head->next;
            tail->next = temp; 
            tail = temp;
            tail->next = nullptr;
        }
        
    }

     void display()
    {
    node *current;
    if(head == NULL){
        cout << "Linked List is empty!";
    }
    else{
        for(current = head; current != NULL; current = current->next) 
        {
            cout << current->data << " ";
        }
        cout << endl;
    }

    }
};

int main() 
{
    LinkedList list;
    list.insertNode(6);
    list.insertNode(10);
    list.insertNode(8);
    list.insertNode(15);
    list.display();
    list.leftRotate(3);
    list.display();
    return 0;
}
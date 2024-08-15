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

    void deleteNode(node* prev){

        if (prev == nullptr) {
            node* curr = head;
            head = head->next;
            if(head == nullptr) tail = nullptr;
            delete curr;
        }

        else{
            node* to_delete = prev->next;
            bool isTail = to_delete == tail;

            prev->next = to_delete->next;
            if(isTail) tail = prev;
            delete to_delete;
        }

        length--;
    }


    void removeLastOccurance(int key){
        node* curr = head;
        node* prev = nullptr;
        node* last = nullptr;
        node* last_prev = nullptr;

        while(curr){
            if(curr->data == key){
                last = curr;
                last_prev = prev;
            } 
            prev = curr;
            curr = curr->next; 
        }

        if(last){
            deleteNode(last_prev);
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
    list.insertNode(4);
    list.insertNode(6);
    list.insertNode(5);
    list.display();
    list.removeLastOccurance(1);
    list.display();
    return 0;
}
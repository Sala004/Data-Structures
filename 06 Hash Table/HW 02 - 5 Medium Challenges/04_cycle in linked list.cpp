#include <iostream>
#include <unordered_set>
using namespace std;

struct NODE {
    int data;
    NODE* next;
    NODE(int data) : 
        data(data), next(nullptr){} 
};

class LinkedList{
private: 
    NODE* head {};
    NODE* tail {};
    int length = 0;

public:
    void insert_end(int value){
        NODE* newNode = new NODE(value);
        if(!head){
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void create_cycle(){
        for(int i = 0; i < 4; i++){
            insert_end(i);
        }

        NODE* now = tail;
        
        for(int i = 0; i < 3; i++){
            insert_end(i + 14);
        }
        tail->next = now;
    }

    void print(){
        NODE* curr = head;
        while(curr){
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void remove_cycle(){
        unordered_set <NODE*> visited;

        NODE* prev = nullptr;
        NODE* curr = head;
        while(curr){
            if(visited.count(curr)){
                prev->next = nullptr;
                tail = prev;
                break;
            }
            visited.insert(curr);
            prev = curr;
            curr = curr->next;
        }
    }
};

int main(){
    LinkedList test;
    test.create_cycle();
    test.remove_cycle();
    test.print();
}
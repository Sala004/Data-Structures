#include <iostream>
#include <cassert>
using namespace std;

class Queue{
private: 
    int addedElements {};
    int size {};
    int front {0};
    int rear {0};
    int* array {};

public:
        Queue(int size):
        size(size){
            array = new int[size];
        }

        int next(int pos){
            pos++;
            if(pos == size){
                pos = 0;
            }
            return pos;
        }

        bool isFull(){
            return addedElements == size;
        }

        bool isEmpty(){
            return addedElements == 0;
        }

        void enqueue(int value){
            assert(!isFull());
            array[rear] = value;
            rear = next(rear);
            addedElements++;
        }

        int dequeue(){
            assert(!isEmpty());
            int value = array[front];
            front = next(front);
            addedElements--;
            return value;
        }

        int frontVal(){
            assert(!isEmpty());
            return array[front];
        }
};

class Stack{
private:
    Queue q;
    int addedElements {};

    void insertAtFront(int value){
    int siz = addedElements;
    q.enqueue(value);
    while(siz--){
        q.enqueue(q.dequeue());
    }
     addedElements++;
    }

public: 

    Stack(int size):
        q(size){
    }

    void push(int value){
        insertAtFront(value);
    }

    void pop(){
        q.dequeue();
        addedElements--;
    }

    int peek(){
        return q.frontVal();
    }

    bool isEmpty(){
        return q.isEmpty();
    }

    bool isFull(){
        return q.isFull();
    }
};

int main(){
    Stack stk(3);
    stk.push(10);
    stk.push(20);
    stk.push(30);
    
    while(!stk.isEmpty()){
        cout << stk.peek() << " ";
        stk.pop();
    }
    return 0;
}
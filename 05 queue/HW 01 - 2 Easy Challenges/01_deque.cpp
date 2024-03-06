#include <iostream>
#include <cassert>
using namespace std;

class deque{
private:
    int addedElements {};
    int size {};
    int front {0};
    int rear {0};
    int* array {};

public:
    deque(int size):
        size(size){
            array = new int[size];
        }
    
    bool isFull(){
        return addedElements == size;
    }
    bool isEmpty(){
        return addedElements == 0;
    }

    int prev(int pos){
        pos--;
        if(pos == -1){
            pos = size - 1;
        }
        return pos;
    }

    int next(int pos){
        pos++;
        if(pos == size){
            pos = 0;
        }
        return pos;
    }

    void enqueueFront(int value){
        assert(!isFull());
        front = prev(front);
        array[front] = value;
        addedElements++;
    }

    void enqueueRear(int value){
        assert(!isFull());
        array[rear] = value;
        rear = next(rear);
        addedElements++;
    }

    void dequeueRear(){
        assert(!isEmpty());
        rear = prev(rear);
        addedElements--;
    }

    void dequeueFront(){
        assert(!isEmpty());
        front = next(front);
        addedElements--;
    }

    void display(){
        for(int curr = front, step = 0; step < addedElements; step++, curr = next(curr)){
            cout << array[curr] << " ";
        }
        cout << endl;
    }
};


int main(){
    deque dq(5);
    //add elements
    dq.enqueueFront(1);
    dq.enqueueFront(2);
    dq.enqueueRear(3);
    dq.enqueueRear(4);
    dq.display();

    //remove elements
    dq.dequeueRear();
    dq.dequeueFront();
    dq.display();
}
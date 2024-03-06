#include <iostream>
#include <cassert>
using namespace std;

class stack{
private:
    int top {};
    int size {};
    int* array;
public:
    stack(int size):
        size(size), top(-1){
        array = new int[size];
    }

    bool isFull(){
        return top == size - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int value){
        assert(!isFull());
        array[++top] = value;
    }

    int pop(){
        assert(!isEmpty());
        return array[top--];
    }

    int peek(){
        return array[top];
    }

    void display(){
        for(int i = 0; i <= top; i++){
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

class queue{
private:
    int size {};
    int addedElements {};
    stack stk1;
    stack stk2;

    void move(stack& from, stack& to){
        while(!from.isEmpty()){
            to.push(from.pop());
        }
    }

public: 
    queue(int size):
        size(size), stk1(size), stk2(size){

    }

    bool isFull(){
        return addedElements == size;
    }

    bool isEmpty(){
        return addedElements == 0;
    }
    void enqueue(int value){ //O(1)
        assert(!isFull());
        stk1.push(value);
        addedElements++;
    }

    int dequeue(){  //O(n)
        assert(!isEmpty());
        if(stk2.isEmpty()){
            move(stk1, stk2);
        }
        int value = stk2.pop();
        addedElements--;
        return value;
    }

    void display(){
        if(!stk2.isEmpty()){
            move(stk1, stk2);
            stk2.display();
        }
        else{
            stk1.display();
        }
    }
};

int main(){
    queue q(5);
    q.enqueue(10); 
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40); //10 20 30 40

    q.dequeue();
    q.dequeue();

    q.display(); //30 40
}
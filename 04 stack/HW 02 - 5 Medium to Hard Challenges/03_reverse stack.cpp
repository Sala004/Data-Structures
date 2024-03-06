#include <iostream>
#include <cassert>
using namespace std;

class stack {
private:
    int size{ };
    int top{ };
    int* array{ };

public:
    stack(int size):
        size(size), top(-1) {
        array = new int[size];
    }

    bool isFull() {
        return size - 1 == top;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int value) {
        assert(!isFull());
        array[++top] = value;
    }

    int pop() {
        assert(!isEmpty());
        return array[top--];
    }

    int length(){
        int len = 0;
        for(int i = 0; i <= top; i++){
            len++;
        }
        return len;
    }

    void insertAtBottom(int value){
        assert(!isFull());
        for(int i = top; i >= 0; i--){
            array[i + 1] = array[i];
        }
        array[0] = value;
    }

    void reverse(){
        if(isEmpty()){
            return;
        }
        int curr = pop();
        reverse();
        insertAtBottom(curr);
    }


    int peek() {
        assert(!isEmpty());
        return array[top];
    }

    void display() {
        for(int i = 0; i <= top; i++){
            cout << array[i] << " ";
        }
    }
};


int main()
{
    stack stk(5);
    stk.push(4);
    stk.push(3);
    stk.push(2);
    stk.push(1);
    stk.reverse();
    stk.display();
}
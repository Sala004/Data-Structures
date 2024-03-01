#include <iostream>
#include <cassert>
using namespace std;

class stack{
private: 
    int size = {};
    int top = {};
    int topII = {};
    int* array = {};
public:
    stack(int size):
    size(size), top(-1), topII(size){
        array = new int[size];
    }
    bool isFull(){
        return top + 1 == topII;
    }

    bool isEmpty(int pos){
        if(pos == 1){
            return top == -1;
        }
        return topII == size;
    }

    void push(int pos, int value){
        assert(!isFull());
        if(pos == 1){
            array[++top] = value;
        }
        else if (pos == 2){
            array[--topII] = value;
        }
    }

    int pop(int pos){
        assert(!isEmpty(pos));
        if(pos == 1){
            return array[top--];
        }
        return array[topII++];
    }

    int peek(int pos){
        assert(!isEmpty(pos));
        if(pos == 1){
            return array[top];
        }
        return array[topII];
    }

    void display(){
        for(int i = 0; i <= top; i++){
            cout << array[i] << " ";
        }
        cout << endl;
        for(int i = size - 1; i >= topII; i--){
            cout << array[i] << " ";
        }
    }

};

int main() {
    stack stk(10);
    stk.push(1, 10);
    stk.push(1, 20);
    stk.push(1, 30);
    stk.pop(1);
    stk.push(2, 40);
    stk.push(2, 50);
    stk.push(2, 60);
    stk.pop(2);
    stk.display();
    return 0;
}

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


    int peek() {
        assert(!isEmpty());
        return array[top];
    }
};

    int reverseNumber(int num){
        int currDigit;
        stack stk(10);
        while(num){
            currDigit = num % 10;
            num /= 10;
            stk.push(currDigit);
        }
        int tens = 1;
        while(!stk.isEmpty()){
            num = stk.pop() * tens + num; 
            tens *= 10;
        }
        return num;
    }

int main()
{
    cout << reverseNumber(1234);
}
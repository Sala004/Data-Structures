#include <iostream>
#include <cassert>
#include <string>
using namespace std;

class stack {
private:
    int size{ };
    int top{ };
    int* array{ };
    int count = 0;
    string result = "";

public:
    stack(int size):
        size(size), top(-1) {
        array = new int[size];
    }

    ~stack() {
        delete[] array; // Deallocate the dynamically allocated array to prevent memory leak
    }

    bool isFull() {
        return top == size - 1; // Corrected condition
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

    string reverseSubwords(string str) {
        string result;
        str += ' ';
        stack stk(str.size());
        for(int i = 0; i < str.size(); i++){
            if(str[i] == ' '){
                while(!stk.isEmpty()){
                    result += stk.pop();
                }
                result += ' ';
            }
            else{
                stk.push(str[i]);
            }
        }
        return result;
    }

int main() {
    string str;
    getline(cin, str);
    cout << reverseSubwords(str);
    return 0;
}

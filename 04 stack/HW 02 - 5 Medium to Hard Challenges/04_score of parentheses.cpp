#include <iostream>
#include <cassert>
using namespace std;

class stack{
private:
    int size { };
    int top { };
    int* array{ };

public:
    stack(int size):
    size(size), top(-1){
        array = new int [size];
    }

    bool isFull(){
        return top == size - 1;
    }

    bool isEmpty(){
        return top == -1;
    }

    void push(int value){
        assert(!isFull());
        array[++top] = value;
    }

    int peek(){
        assert(!isEmpty());
        return array[top];
    }

    int pop(){
        assert(!isEmpty());
        return array[top--];
    }
};

int scoreOfParentheses(string s) {
	stack stk(s.size());
	int score = 0;
	for (char c : s) {
		if (c == '(') {
			stk.push(score);
			score = 0;
		}
		else {
            //it will be 1 in the case ()
			score = stk.peek() + max(score * 2, 1);
			stk.pop();
		}
	}
	return score;
}

int main() {
	string str = "()()()()((()(((()))((())(((((()))()()())))))))";
	cout << scoreOfParentheses(str);
}
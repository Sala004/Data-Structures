#include <iostream>
#include <cassert>
#include <math.h>
using namespace std;

typedef double type;

class Stack {
private:

	struct Node {
		double data { };
		Node* next { };
		Node(double data) :
				data(data) {
		}
	};

	Node *head { };		// Points to Top

public:
	~Stack() {
		while (!isEmpty())
			pop();
	}
	void display() {
		for (Node* cur = head; cur; cur = cur->next)
			cout << cur->data << " ";
		cout << "\n";
	}

	void push(double value) {

		Node* item = new Node(value);
		item->next = head;
		head = item;

	}

	double pop() {
		assert(!isEmpty());
		double element = head->data;
		Node* temp = head;
		head = head->next;
		delete temp;
		return element;
	}

	double peek() {
		assert(!isEmpty());
		double element = head->data;
		return element;
	}

	int isEmpty() {
		return !head;
	}
};

    double operation(char c, double op1, double op2){
        if(c == '+'){
            return op2 + op1;
        }
        else if(c == '-'){
            return op2 - op1;
        }
        else if(c == '*'){
            return op2 * op1;
        }
        else if(c == '/'){
            return op2 / op1;
        }
        return pow(op2, op1);
    }
    double evaluatePostfix(string postfix){
        Stack stk;
        for(int i = 0; i < postfix.size(); i++){
            if(isdigit(postfix[i])){
                stk.push(postfix[i] - '0');
            }
            else{
                double op1 = stk.pop();
                double op2 = stk.pop();
                double result = operation(postfix[i], op1, op2);
                stk.push(result);
            }
        }
        return stk.peek();
    }

int main() {
    string str = "432^^";
    cout << "result: " << evaluatePostfix(str);
    return 0;
}
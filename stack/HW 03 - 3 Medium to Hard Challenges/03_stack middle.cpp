#include <iostream>
#include <cassert>
#include <math.h>
using namespace std;


class Stack {
private:
	// Tip: We can make this struct internally
	struct Node {
		int data { };
		Node* next { };
		Node(int data) :
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
        Node* Middle = findMiddle();
		for (Node* cur = head; cur; cur = cur->next){
            if(cur == Middle){
                cout << '[' << cur->data << ']' << " ";
                continue;
            }
			cout << cur->data << " ";
        }
		cout << "\n";
	}

	void push(int value) {
		Node* item = new Node(value);
		item->next = head;
		head = item;
	}

	int pop() {
		assert(!isEmpty());
		int element = head->data;
		Node* temp = head;
		head = head->next;
		delete temp;
		return element;
	}

	int peek() {
		assert(!isEmpty());
		int element = head->data;
		return element;
	}

	int isEmpty() {
		return !head;
	}

    Node* findMiddle(){
        Node* slow = head;
        Node* fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};


int main() {
    Stack stk;
    for(int i = 0; i < 10; i++){
        stk.push(i);
        stk.display();
    }
    while(!stk.isEmpty()){
        stk.pop();
        stk.display();
    }
}
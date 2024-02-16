#include <iostream>
#include <vector>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;

    ~node() {}
};

class LinkedList {
private:
    node* head = nullptr;
    node* tail = nullptr;
    int length = 0;

public:
    void insertNode(int value) {
        node* new_node = new node;
        new_node->data = value;
        if (head == nullptr) {
            head = tail = new_node;
            new_node->next = nullptr;
        }
        else {
            tail->next = new_node;
            new_node->next = nullptr;
            new_node->prev = tail;
            tail = new_node;
        }
        length++;
    }

void link(node* first, node* second) {
    if (first) {
         first->next = second;
    }
    if (second) {
         second->prev = first;
    }
}
void mergeLists(LinkedList &other){


        if (!other.head)
			return;

		if (head) {
			node* cur1 = head;
			node* cur2 = other.head;
			node* last { };
			head = nullptr;

			while (cur1 && cur2) {
				node* next { };
				// pick the smallest among the 2 lists and then link it
				if (cur1->data <= cur2->data) {
					next = cur1;
					cur1 = cur1->next;
				} else {
					next = cur2;
					cur2 = cur2->next;
				}
				link(last, next);
				last = next;
				if (!head)	// first step is the head
					head = last;
			}
			if (cur2) {	// our tail is from 2nd
				tail = other.tail;
				link(last, cur2);
			} else if (cur1) {
				link(last, cur1);
			}
		} else {	// use its data
			head = other.head;
			tail = other.tail;
		}
}

void display() {
    node* current = head;
    if (current == nullptr) {
        cout << "Linked List is empty!" << endl;
    }
    else {
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}

};

int main() {
LinkedList list;
list.insertNode(10);
list.insertNode(20);
list.insertNode(30);
list.insertNode(40);
list.insertNode(50);
LinkedList list2;
list2.insertNode(15);
list2.insertNode(17);
list2.insertNode(22);
list2.insertNode(24);
list2.insertNode(35);
list.display();
list.mergeLists(list2);
list.display();

return 0;
}
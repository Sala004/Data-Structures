#include <iostream>
#include <cassert>
using namespace std;

class Queue {
	int size { };
	int front { 0 };
	int rear { 0 };
	int added_elements { };
	int *array { };

public:
	Queue(int size) :
		size(size) {
		array = new int[size];
	}

	~Queue() {
		delete[] array;
	}

	int next(int pos) {
		++pos;
		if (pos == size)
			pos = 0;
		return pos;
	}

	void enqueue(int value) {
		assert(!isFull());
		array[rear] = value;
		rear = next(rear);
		added_elements++;
	}

	int dequeue() {
		assert(!isEmpty());
		int value = array[front];
		front = next(front);
		--added_elements;
		return value;
	}

	void display() {
		for (int cur = front, step = 0; step < added_elements; ++step, cur = next(cur))
			cout << array[cur] << " ";
		cout << "\n";
	}

	int isEmpty() {
		return added_elements == 0;
	}

	bool isFull() {
		return added_elements == size;
	}
};

class PriorityQueue{
private:
    int size {};
    int addedElements {};
    Queue q1, q2, q3;

public:
    PriorityQueue(int size):
    size(size), q1(size), q2(size), q3(size){

    }

    void enqueue(int value, int priority){
        assert(!isFull());

        if(priority == 1)
            q1.enqueue(value);
        else if(priority == 2)
            q2.enqueue(value);
        else if(priority == 3)
            q3.enqueue(value);

        else{
            return;
        }
    
        addedElements++;
    }

    int dequeue(){
        assert(!isEmpty());
        addedElements--;

        if(!q3.isEmpty())
            return q3.dequeue();

        else if(!q2.isEmpty())
            return q2.dequeue();

        return q3.dequeue();

    }

    bool isFull(){
        return addedElements == size;
    }

    bool isEmpty(){
        return addedElements == 0;
    }

    void display(){
        cout << "Priority #3 ";
        q3.display();
        cout << "Priority #2 ";
        q2.display();
        cout << "Priority #1 ";
        q1.display();
    }
    
};


int main(){
    PriorityQueue tasks(8);
    tasks.enqueue(1131, 1);
    tasks.enqueue(3111, 3);
    tasks.enqueue(2211, 2);
    tasks.enqueue(3161, 3);

    tasks.display();

    cout << tasks.dequeue() << endl; //3111
    cout << tasks.dequeue() << endl; //3161

}
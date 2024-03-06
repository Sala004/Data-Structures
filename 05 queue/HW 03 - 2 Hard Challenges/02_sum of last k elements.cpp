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
		cout << "\n\n";
	}

	int isEmpty() {
		return added_elements == 0;
	}

	bool isFull() {
		return added_elements == size;
	}
};
class lastKNumbersSum{
private: 
    int k;
    int sum {};
    int addedElements {};
    Queue q;

public:
    lastKNumbersSum(int k):
        k(k), q(k+1){
    }
    int next(int newNum){
        q.enqueue(newNum);
        sum += newNum;

        if(addedElements > k){
            sum -= q.dequeue();
            addedElements--;
        }

        return sum;
    }

};

int main() {
    lastKNumbersSum test(3);
    int num;
    while(cin >> num){
        cout << test.next(num) << "\n";
    }

    return 0;
}



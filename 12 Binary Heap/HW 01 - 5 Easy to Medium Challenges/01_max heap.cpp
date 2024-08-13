#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class MaxHeap{
private: 
    int size {};
    int *arr {};
    int capacity {1000};

    int left(int node){
        int p = 2 * node + 1;
        return p >= size ? -1 : p;
    }

    int right(int node){
        int p = 2 * node + 2;
        return p >= size ? -1 : p;
    }

    int parent(int node){
        return node == 0? -1 : (node - 1) / 2; 
    }

    void heapifyUp(int childPos) {
        int par_pos = parent(childPos);
        if(childPos == 0 || arr[par_pos] > arr[childPos]) return;

        swap(arr[par_pos], arr[childPos]);
        heapifyUp(par_pos);
    }

    void heapifyDown(int parentPos){
        int childPos = left(parentPos);
        int rightPos = right(parentPos);

        if(childPos == -1) return; 

        //is right bigger than left?
        if(rightPos != -1 && arr[rightPos] > arr[childPos]) {
            childPos = rightPos;
        }

        if(arr[parentPos] < arr[childPos]){
            swap(arr[parentPos], arr[childPos]);
            heapifyDown(childPos);
        }
    }

public:
    MaxHeap(){
        arr = new int[capacity] {};
        size = 0;
    }

    ~MaxHeap(){
        delete[] arr;
        arr = nullptr;
    }

    void push(int key){
        assert(size + 1 <= capacity);
        arr[size++] = key;
        heapifyUp(size - 1);
    }

    void pop(){
        assert(!isempty());
        arr[0] = arr[--size];
        heapifyDown(0);
    }

    int top(){
        assert(!isempty());
        return arr[0];
    }

    bool isempty(){
        return size == 0;
    }
};

void creat_heap_nlogn() {
	MaxHeap heap;

	vector<int> v { 2, 17, 22, 10, 8, 37,
		14, 19, 7, 6, 5, 12, 25, 30 };

	for (int i = 0; i < v.size(); ++i)
		heap.push(v[i]);

	while (!heap.isempty()) {
		cout << heap.top() << " ";
		heap.pop();
	}
	// 2 5 6 7 8 10 12 14 17 19 22 25 30 37
}

int main(){
    creat_heap_nlogn();
}
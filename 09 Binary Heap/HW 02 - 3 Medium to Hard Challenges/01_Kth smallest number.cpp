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

    int getSize() const{
        return size;
    }

    int top(){
        assert(!isempty());
        return arr[0];
    }

    bool isempty(){
        return size == 0;
    }
};

class KthSmallestNumer{
private:
    int k;
    MaxHeap q;

public:
    KthSmallestNumer(int k): k(k) { }

    int add(int new_num){
        if(q.getSize() < k){
            q.push(new_num);
        }
        else if(new_num < q.top()){
            q.pop();
            q.push(new_num);
        }

        return q.top();
    }

};

int main(){
    KthSmallestNumer processor(4);

	int num;
	while (cin >> num)
		cout << processor.add(num) << "\n";

	return 0;
}
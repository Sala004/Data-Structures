#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class MinHeap{
private: 
    int size {};
    pair<int, int> *arr {};
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
        if(childPos == 0 || arr[par_pos].second <= arr[childPos].second) return;

        swap(arr[par_pos], arr[childPos]);
        heapifyUp(par_pos);
    }

    void heapifyDown(int parentPos){
        int childPos = left(parentPos);
        int rightPos = right(parentPos);

        if(childPos == -1) return; 

        //is right bigger than left?
        if(rightPos != -1 && arr[rightPos].second < arr[childPos].second) {
            childPos = rightPos;
        }

        if(arr[parentPos].second > arr[childPos].second){
            swap(arr[parentPos], arr[childPos]);
            heapifyDown(childPos);
        }
    }

public:
    MinHeap(){
        arr = new pair<int, int>[capacity] {};
        size = 0;
    }

    ~MinHeap(){
        delete[] arr;
        arr = nullptr;
    }

    void push(pair<int, int> key){
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
        return arr[0].first;
    }

    bool isempty(){
        return size == 0;
    }
};

class priorityQueue{
private:
    MinHeap pq;

public:
    void enqueue(pair<int, int> key){
        pq.push(key);
    }

    int dequeue(){
        int deleted = pq.top();
        pq.pop();
        return deleted;
    }

    bool isempty(){
        return pq.isempty();
    }
};


int main(){
    priorityQueue tasks;
    tasks.enqueue({1131, 1});
    tasks.enqueue({3111, 3});
    tasks.enqueue({2211, 2});
    tasks.enqueue({3161, 7});
    tasks.enqueue({1535, 1});

    while(!tasks.isempty()){
        cout << tasks.dequeue() << " ";
    }
}
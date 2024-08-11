#include <iostream>
#include <vector>
using namespace std;

class MinHeap{
private: 
    int size {};
    int *arr {};

    void heapify(){
        for(int i = size / 2 - 1; i >= 0; i--){
            sink(i);
        }
    }

    int left(int node){
        int p = 2 * node + 1;
        return p >= size ? -1 : p;
    }

    int right(int node){
        int p = 2 * node + 2;
        return p >= size ? -1 : p;
    }

    void sink(int parent_pos){
        int child_pos = left(parent_pos);
        int right_pos = right(parent_pos);

        if(child_pos == -1) return;

        if(right_pos != -1 && arr[right_pos] < arr[child_pos]) child_pos = right_pos;

        if(arr[child_pos] < arr[parent_pos]) {
            swap(arr[child_pos], arr[parent_pos]);
            sink(child_pos);
        }
    }

    int top(){
        return arr[0];
    }

    void pop(){
        arr[0] = arr[--size];
        sink(0);
    }

    bool isempty(){
        return size == 0;
    }

public: 
    MinHeap(vector<int> &v){
        size = v.size();
        arr = new int[size];

        for(int i = 0; i < size; i++){
            arr[i] = v[i];
        }

        heapify();
    }

    ~MinHeap(){
        delete[] arr;
    }

    vector<int> getSorted(vector<int> &v){
        int old_size = size;
        int curr = 0;
        while(!isempty()){
            v[curr++] = top();
            pop();
        }

        size = old_size;

        return v;
    }
};

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() <= 1) return nums;
        MinHeap heap(nums);
        return heap.getSorted(nums);
    }
};
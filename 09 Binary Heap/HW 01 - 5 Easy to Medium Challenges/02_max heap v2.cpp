#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

class MinHeap {
private:
    int *array {};
    int size {};
    int capacity { 1000 };

    int left(int node) {
        int p = 2 * node + 1;
        if (p >= size)
            return -1;
        return p;
    }

    int right(int node) {
        int p = 2 * node + 2;
        return p >= size ? -1 : p;
    }

    int parent(int node) {
        return node == 0 ? -1 : (node - 1) / 2;
    }

    void heapify_up(int child_pos) {
        int par_pos = parent(child_pos);
        if (child_pos == 0 || array[par_pos] <= array[child_pos])
            return;

        swap(array[child_pos], array[par_pos]);
        heapify_up(par_pos);
    }

    void heapify_down(int parent_pos) { // O(logn)
        int child_pos = left(parent_pos);
        int right_child = right(parent_pos);

        if (child_pos == -1) // no children
            return;

        // is right smaller than left?
        if (right_child != -1 && array[right_child] < array[child_pos])
            child_pos = right_child;

        if (array[parent_pos] > array[child_pos]) {
            swap(array[parent_pos], array[child_pos]);
            heapify_down(child_pos);
        }
    }

    void heapify() { // O(n)
        for (int i = size / 2 - 1; i >= 0; --i)
            heapify_down(i);
    }

public:
    MinHeap() {
        array = new int[capacity] {};
        size = 0;
    }

    MinHeap(const vector<int> &v) {
        assert(v.size() <= capacity);
        array = new int[capacity] {};
        size = v.size();

        for (int i = 0; i < size; i++) {
            array[i] = v[i];
        }

        heapify();
    }

    ~MinHeap() {
        delete[] array;
        array = nullptr;
    }

    void push(int key) {
        assert(size < capacity);
        array[size++] = key;
        heapify_up(size - 1);
    }

    void pop() {
        assert(!isempty());
        array[0] = array[--size];
        heapify_down(0);
    }

    int top() const {
        assert(!isempty());
        return array[0];
    }

    bool isempty() const {
        return size == 0;
    }
};

class MaxHeap {
private:
    MinHeap heap;

    // multiple values with -1
    vector<int> multiply_neg(const vector<int> &v) {
        vector<int> res = v;
        for (int i = 0; i < (int)res.size(); ++i)
            res[i] *= -1;
        return res;
    }

public:
    MaxHeap() {}

    MaxHeap(const vector<int> &v) : heap(multiply_neg(v)) {}

    int top() const {
        return -heap.top(); // notice -1
    }

    void push(int key) {
        heap.push(-key);
    }

    void pop() {
        heap.pop();
    }

    bool isempty() const {
        return heap.isempty();
    }
};

void creat_heap_nlogn() {
    vector<int> v { 2, 17, 22, 10, 8, 37, 14, 19, 7, 6, 5, 12, 25, 30 };
    MaxHeap heap(v);

    while (!heap.isempty()) {
        cout << heap.top() << " ";
        heap.pop();
    }
    // Output should be: 37 30 25 22 19 17 14 12 10 8 7 6 5 2
}

int main() {
    creat_heap_nlogn();
    return 0;
}

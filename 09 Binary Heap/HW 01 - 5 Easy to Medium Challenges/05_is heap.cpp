#include <iostream>
#include <cassert>
#include <vector>
using namespace std;


int left(int node, int size){
    int p = 2 * node + 1;
    return p >= size ? - 1 : p;
}

int right(int node, int size){
    int p = 2 * node + 2;
    return p >= size ? -1 : p;
}

bool isHeap(vector<int> &arr, int size){
    for(int i = 0; i <= (size - 2) / 2; i++){
        int left_pos = left(i, size);
        int right_pos = right(i, size);

        if(left_pos != -1 && arr[left_pos] < arr[i]){
            return false;
        }

        if(right_pos != -1 && arr[right_pos] < arr[i]){
            return false;
        }
    }

    return true;
}

int main(){

	vector<int> v { 2, 5, 12, 7,6, 22, 14, 19, 10, 17, 8, 37, 25, 30 };

    cout << isHeap(v, v.size());
    
}
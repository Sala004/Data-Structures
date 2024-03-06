#include <iostream>
#include <cassert>
using namespace std;
class vector
{
private:
    int *arr = nullptr;
    int size = 0;
    int capacity;
    
    void expand_capacity()
    {
        capacity *= 2;
        int *arr2 = new int[capacity];
        for(int i = 0; i < size; i++){
            arr2[i] = arr[i];
        }
        swap(arr, arr2);
        delete[] arr2;
    }
public:
    vector(int size):
    size(size) {
        capacity = size + 10;
        arr = new int[capacity] {0};
    }
    void set(int indx, int value){
        if(indx > size){
            size++;
        }
        arr[indx] = value;
    }

    void right_rotate(){
        int temp = arr[size];
        for(int i = size; i > 0; i--){
            arr[i] = arr[i - 1];
        }
        arr[0] = temp;
    }

    void left_rotate(){
        int temp = arr[0];
        for(int i = 0; i < size; i++){
            arr[i] = arr[i + 1];
        }
        arr[size] = temp;
    }

    void right_rotate(int times){
        while(times--){
            int temp = arr[size];
            for(int i = size; i > 0; i--){
                arr[i] = arr[i - 1];
            }
            arr[0] = temp;
        }
    }

    int pop(int indx){
        assert(0 <= indx && indx <= size);
        int value = arr[indx];
        for(int i = size; i > indx; i--){
            arr[i - 1] = i;
        }

        size--;
        return value;
    }

    int find_transposition(int value){
        for(int i = size; i >= 0; i--){
            if(arr[i] == value){
                if(i == 0){
                    return 0;
                }
                swap(arr[i], arr[i - 1]);
                return i - 1;
            }
        }
        return -1; //if NOT found
    }

    void print(){
        for(int i = 0; i <= size; i++) {
            cout << arr[i] << endl;
        }
    }
};
int main() {
    vector v(2);
    for(int i = 0; i < 5; i++){
        v.set(i, i);
    }
    v.print();
    cout << "After transposition" << endl;
    v.find_transposition(3);
    v.print();
    cout << "After deletion";
    v.pop(3);
    v.print();
    cout << "After right rotation with steps" << endl;
    v.right_rotate(2);
    v.print();
    v.right_rotate();
    cout << "After right rotation" << endl;
    v.print();
    cout << "After left rotation" << endl;
    v.left_rotate();
    v.print();
    return 1;
}
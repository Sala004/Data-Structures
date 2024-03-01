#include <iostream>
using namespace std;

class stack{
private:
    int size{};
    int addedElements{};
    int* array {};

public:
    stack(int size):
    size(size), addedElements(0){
        array = new int[size];
    }

    bool isFull() {
        return addedElements == size;
    }

    bool isEmpty() {
        return addedElements == 0;
    }

    bool push(int value){
        if(isFull()){
            return false;
        }
        for(int i = addedElements - 1; i >= 0; --i)
            array[i + 1] = array[i];
        array[0] = value;
        ++addedElements;
        return true;
    }

    bool pop(){
        if(isEmpty()){
            return false;
        }
        for(int i = 1; i < addedElements; i++)
            array[i - 1] = array[i];
        --addedElements;
        return true;
    }

    void display() {
        for(int i = 0; i < addedElements; i++){
            cout << array[i] << " ";
        }
    }
};
int main() {
    stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    //30 20 10
    s.pop();
    //20 10
    s.display();
    return 0;
}
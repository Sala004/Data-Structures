#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class stack{
private:
    int size { };
    int top { };
    int* array{ };

public:
    stack(int size):
    size(size), top(-1){
        array = new int [size];
    }

    bool isFull(){
        return top == size - 1;
    }

    bool isEmpty(){
        return top == -1;
    }

    void push(int value){
        assert(!isFull());
        array[++top] = value;
    }

    int peek(){
        assert(!isEmpty());
        return array[top];
    }

    int pop(){
        assert(!isEmpty());
        return array[top--];
    }

    void displayReversed() {
        for(int i = 0; i <= top; i++){
            cout << array[i] << " ";
        }
        cout << "\n";
    }
};

void asteroidCollision(int arr[] , int len){
    stack result(len);
    for(int i = 0; i < len; i++){
        int curr = arr[i]; 
        bool isCollide = false;
        while(!result.isEmpty() && curr < 0 && result.peek() > 0){
            if(curr + result.peek() < 0){
                result.pop(); 
                continue; //check if more will collide
            }
            else if(-curr == result.peek()){
                result.pop();
            }
            isCollide = true;
            break;
        }
        if(!isCollide){
            result.push(curr); //10 
        }
    }
    result.displayReversed();
}


void test1(){
    int arr[] = {-2, -1, 1, 2};
    asteroidCollision(arr, 4);
}

void test2(){
    int arr[] = {5, 10, -5};
    asteroidCollision(arr, 3);
}

void test3(){
    int arr[] = {-2, -2, 1, -2};
    asteroidCollision(arr, 4);
}

void test4() {
    int arr[] = {8, -8};
    asteroidCollision(arr, 2);
}


int main() {
    test1();
    test2();
    test3();
    test4();
}
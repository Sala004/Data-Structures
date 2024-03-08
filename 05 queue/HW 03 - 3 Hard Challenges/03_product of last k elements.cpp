#include <iostream>
#include <deque>
using namespace std;

class ProductOfNumbers {
public:
    deque <int> deq;
    int product = 1;
    ProductOfNumbers() {
        deq.push_back(product);
    }
    
    void add(int num) {
        if(num == 0){
            deq.clear();
            product = 1;
        }
        else if(deq.empty()){
            product = num;
        }
        else{
            product *= num;
        }
        deq.push_back(product);
    }
    
    int getProduct(int k) {
        if(deq.empty() || k >= deq.size()){
            return 0;
        }
        return deq.back() / deq[deq.size() - k - 1];
    }
};
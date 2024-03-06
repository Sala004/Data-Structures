#include <iostream>
#include <cstring>
using namespace std;

struct node{
    string data;
    node* next = nullptr;
    node* prev = nullptr;
};

class BrowserHistory {
public:
    node* curr = nullptr;
    BrowserHistory(string homepage) {
        curr = new node();
        curr->data = homepage; //leectcode
    }
    
    void visit(string url) {
        node* temp = new node();
        temp->data = url; //google
        curr->next = temp; //leetcode -> google
        temp->prev = curr; 
        curr = temp;
    }
    
    string back(int steps) {
        while(steps-- && curr->prev){
            curr = curr->prev;
        }
        return curr->data;
    }
    
    string forward(int steps) {
        while(steps-- && curr->next){
            curr = curr->next;
        }
        return curr->data;
    }
};

int main(){
    BrowserHistory obj("leetcode.com");
    obj.visit("google.com");
    obj.visit("facebook.com");
    obj.visit("youtube.com");
    cout << obj.back(1) << "  ";
    cout << obj.back(1) << "  ";
    cout << obj.forward(1) << "  ";
    obj.visit("linkedin.com");
    cout << obj.forward(2);
    return 0;
}
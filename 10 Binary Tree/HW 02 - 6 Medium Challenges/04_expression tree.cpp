#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class BinaryTree{
private:
  
    char data { };
    BinaryTree* left { };
    BinaryTree* right { };

public:
    BinaryTree (int data):
        data(data) {}

    BinaryTree(string postfix){
        stack<BinaryTree*> stk;

        for(int i = 0; i < postfix.size(); i++){
            BinaryTree* curr = new BinaryTree(postfix[i]);

            if(!isdigit(postfix[i])){
                curr->right = stk.top();
                stk.pop();
                curr->left = stk.top();
                stk.pop();
            }

            stk.push(curr);
        }

        BinaryTree* root = stk.top();
		this->data = root->data;
		this->left = root->left;
		this->right = root->right;
    }

    void add(vector<int> values, vector<char> direction){
        BinaryTree* curr = this;

        for(int i = 0; i < values.size(); i++){
            if(direction[i] == 'L'){
                if(!curr->left){
                    curr->left = new BinaryTree(values[i]);
                }
                curr = curr->left;
            }
            else{
                if(!curr->right){
                    curr->right = new BinaryTree(values[i]);
                }
                curr = curr->right;
            }

        }
    }


    void printInOrder(){
        if(left){
            left->printInOrder();
        }
        cout << data << " ";
        if(right){
            right->printInOrder();
        }
    }
    

};


int main(){
    BinaryTree tree("23+4*");
    tree.printInOrder();
}
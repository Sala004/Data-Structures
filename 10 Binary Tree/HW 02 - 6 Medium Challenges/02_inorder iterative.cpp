#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class BinaryTree{
private:
  
    int data { };
    BinaryTree* left { };
    BinaryTree* right { };

public:
    BinaryTree (int data):
        data(data) {}

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
    
   void inorderIterative() {
    stack<BinaryTree*> stk;
    BinaryTree* current = this;  

    while (current || !stk.empty()) {
        while (current) {
            stk.push(current);
            current = current->left;
        }

        current = stk.top();
        stk.pop();
        cout << current->data << " ";

        current = current->right;
    }
}

};


int main(){
    BinaryTree tree(1);
    tree.add({2, 4, 7}, {'L', 'L', 'L'});
    tree.add({2, 4, 8}, {'L', 'L', 'R'});
    tree.add( { 2, 5, 9 }, { 'L', 'R', 'R'});
    tree.add({3, 6, 10}, {'R', 'R', 'L'});

    tree.inorderIterative();

}
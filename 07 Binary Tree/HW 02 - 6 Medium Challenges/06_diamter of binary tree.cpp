#include <iostream>
#include <vector>
#include <algorithm>
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

    int Height(BinaryTree* root){
        if (root == nullptr) return 0;
        
        int leftHeight = Height(root->left);
        int rightHeight = Height(root->right);
        
        return 1 + max(leftHeight, rightHeight);
    }

    int diameter(BinaryTree* root) {
        if (!root) return 0;

        int left_height = Height(root->left);
        int right_height = Height(root->right);

        int right_diam = diameter(root->right);
        int left_diam = diameter(root->left);


 
        return max(left_height + right_height + 1, max(right_diam, left_diam));
    }
    

};


int main(){
    BinaryTree tree(1);
    tree.add({2, 4, 7}, {'L', 'L', 'L'});
    tree.add({2, 4, 8}, {'L', 'L', 'R'});
    tree.add( { 2, 5, 9 }, { 'L', 'R', 'R'});
    tree.add({3, 6, 10}, {'R', 'R', 'L'});

    cout << tree.diameter(&tree);
}
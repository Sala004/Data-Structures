#include <iostream>
using namespace std;

class BinarySearchTree{
private:
    int val;
    BinarySearchTree* left {};
    BinarySearchTree* right {};
public: 
    BinarySearchTree(int val, BinarySearchTree* left = nullptr, BinarySearchTree* right = nullptr):
        val(val), right(right), left(left) { };

    BinarySearchTree* maxNode(BinarySearchTree* curr){
        while(curr && curr->right){
            curr = curr->right;
        }
        return curr;
    }

    BinarySearchTree* deleteNode(BinarySearchTree* root, int key) {
        if(!root) return nullptr;

        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else{
            BinarySearchTree* tmp = root;
            if(!root->right && !root->left){
                root = nullptr;
            }
            else if(!root->right){
                root = root->left;
            }
            else if(!root->left){
                root = root->right;
            }
            else{
                BinarySearchTree* mx = maxNode(root->left);
                root->val = mx->val;
                root->left = deleteNode(root->left, root->val);
                tmp = nullptr; 
            }
            if(tmp) delete tmp;
        }

        return root;
    }
};

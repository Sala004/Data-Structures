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

    BinarySearchTree* Delete(BinarySearchTree* root){
            BinarySearchTree* tmp = root;
            if(!root->right && !root->left){
                return nullptr;
            }
            else if(!root->right){
                return root->left;
            }
            else if(!root->left){
                return root->right;
            }

            BinarySearchTree* leftMx = maxNode(root->left);
            BinarySearchTree* rightChild = root->right;
            leftMx->right = rightChild;

            if(tmp) delete tmp;
            return root->left;
    }

    BinarySearchTree* deleteNode(BinarySearchTree* root, int key) {
        if(!root) return nullptr;
        if(root->val == key) return Delete(root);
        BinarySearchTree* dummy = root;

        while(root){
            if(key < root->val){
                if(root->left && root->left->val == key){
                    root->left = Delete(root->left);
                    break;
                }
                else{
                    root = root->left;
                }
            }

            else if(key > root->val){
                if(root->right && root->right->val == key){
                    root->right = Delete(root->right);
                    break;
                }
                else{
                    root = root->right;
                }
            }

        }

        return dummy;
    }

};
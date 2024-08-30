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

    void insert(int target) {
		if (target < val) {
			if (!left) {
				left = new BinarySearchTree(target);
			} else
				left->insert(target);
		} else if (target > val) {
			if (!right)
				right = new BinarySearchTree(target);
			else
				right->insert(target);
		} // else: exists already
	}


    void special_delete(BinarySearchTree* child){
        val = child->val;
        left = child->left;
        right = child->right;
        delete child;
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
                root->special_delete(root->left);
            }
            else if(!root->left){
                root->special_delete(root->right);
            }
            else{
                BinarySearchTree* mx = maxNode(root->left);
                root->val = mx->val;
                root->left = deleteNode(root->left, root->val);
                tmp = nullptr; 
            }
        }

        return root;
    }
};

int main(){
    BinarySearchTree tree(10);
    tree.insert(5);
    tree.deleteNode(&tree, 10);
    return 0;
}
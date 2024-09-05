#include <iostream>
#include <vector>
using namespace std;


class AVLTree{
private:
    struct BinaryNode
    {
        int data {};
        int height {};
        int count { 1 };
        BinaryNode* left {};
        BinaryNode* right {};

        BinaryNode(int data) : data(data) { }

        int child_height(BinaryNode* node){
            if(!node) {
                return -1;
            }

            return node->height;
        }

        int child_count(BinaryNode* node){
            if(node == nullptr){
                return 0;
            }

            return node->count;
        }

        void update_height(){
            height = 1 + max(child_height(left), child_height(right));
            count = 1 + child_count(left) + child_count(right);
        }

        int balance_factor(){
            return child_height(left) - child_height(right);
        }
    };
private:

    BinaryNode* root {};

    BinaryNode* right_rotation(BinaryNode* old_root){
        BinaryNode* new_root = old_root->left;
        BinaryNode* transferred_subtree = new_root->right;

        new_root->right = old_root;
        old_root->left = transferred_subtree;

        old_root->update_height();
        new_root->update_height();

        return new_root;
    }

    BinaryNode* left_rotation(BinaryNode* old_root){
        BinaryNode* new_root = old_root->right;
        BinaryNode* transferred_subtree = new_root->left;

        new_root->left = old_root;
        old_root->right = transferred_subtree;

        old_root->update_height();
        new_root->update_height();

        return new_root;
    }

    BinaryNode* balance(BinaryNode* node){
        if(node->balance_factor() == 2){ //left
            if(node->left->balance_factor() == -1) //left right
                node->left = left_rotation(node->left); // left left

            node = right_rotation(node);
        }
        else if(node->balance_factor() == -2){ //right
            if(node->right->balance_factor() == 1) // left
                node->right = right_rotation(node->right); //right right

            node = left_rotation(node);
        }

        return node;
    }

    BinaryNode* insert(int target, BinaryNode* node){
        if(target < node->data){
            if(!node->left){
                node->left = new BinaryNode(target);
            }
            else{
                node->left = insert(target, node->left);
            }
        }
        else if(target > node->data){
            if(!node->right){
                node->right = new BinaryNode(target);
            }
            else{
                node->right = insert(target, node->right);
            }
        }

        node->update_height();
        return balance(node);
    }

    int upper_bound_count(int target, BinaryNode* node){
        if(!node) return 0;

        if(node->data > target){
            int sum = 1;
            if(node->right){
                sum += node->right->count;
            }
            return sum + upper_bound_count(target, node->left);
        }

        return upper_bound_count(target, node->right);
    }


public: 
    void insert_value(int target){
        if(!root){
            root = new BinaryNode(target);
        }

        else{
            root = insert(target, root);
        }
    }

    //Complexity: O(n log n)
    int count_inversion(const vector<int> &vec){
        int sum = 0;

        for(int i = 0; i < vec.size(); i++){
            insert_value(vec[i]);
            sum += upper_bound_count(vec[i], root);
        }

        return sum;
    }

};


int main(){
    AVLTree tree;
    vector<int> vec = {10, 5, 8, 2, 12, 6};

    cout << tree.count_inversion(vec);
    
    
}
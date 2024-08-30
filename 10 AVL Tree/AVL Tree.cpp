#include <iostream>
using namespace std;


class AVLTree{
private:
    struct BinaryNode
    {
        int data {};
        int height {};
        BinaryNode* left {};
        BinaryNode* right {};

        BinaryNode(int data) : data(data) { }

        int child_height(BinaryNode* node){
            if(!node) {
                return -1;
            }

            return node->height;
        }

        int update_height(){
            return height = 1 + max(child_height(left), child_height(right));
        }

        int balance_factor(){
            return child_height(left) - child_height(right);
        }
    };

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

    BinaryNode* min_node(BinaryNode* curr){
        while(curr->left){
            curr = curr->left;
        }

        return curr;
    }

    BinaryNode* delete_node(int target, BinaryNode* node){
        if(!node) return nullptr; //base case

        if(target < node->data){
            node->left = delete_node(target, node->left);
        }
        else if(target > node->data){
            node->right = delete_node(target, node->right);
        }
        else{ //Node to be deleted found
            BinaryNode* temp = node;
            if(!node->left && !node->right){  //case 1: leaf node
                node = nullptr;
            }
            else if(!node->right){ //case 2: has left only
                node = node->left;
            }
            else if(!node->left){ //case 3: has right only
                node = node->right;
            }

            else{ //case 4: has two children
                BinaryNode* mn = min_node(node);
                node->data = mn->data;
                node->right = delete_node(mn->data, node->right);
                temp = nullptr;
            }

            if(temp){
                delete temp;
            }

        }

        if(node){ //Found ? then handle
            node->update_height();
            node = balance(node);
        }

        return node;
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

    void delete_value(int target){
        if(root){
            root = delete_node(target, root);
        }
    }
    
};


int main(){

}
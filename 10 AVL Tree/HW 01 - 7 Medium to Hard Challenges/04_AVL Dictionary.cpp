#include <iostream>
using namespace std;


class AVLTree{
private:
    struct BinaryNode
    {
        string data {};
        int height {};
        bool is_full_word {};
        BinaryNode* left {};
        BinaryNode* right {};

        BinaryNode(string data, bool is_full_word) : data(data), is_full_word(is_full_word) { }

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

    BinaryNode* insert(string target, BinaryNode* node, bool is_full_word){
        if(target < node->data){
            if(!node->left){
                node->left = new BinaryNode(target, is_full_word);
            }
            else{
                node->left = insert(target, node->left, is_full_word);
            }
        }
        else if(target > node->data){
            if(!node->right){
                node->right = new BinaryNode(target, is_full_word);
            }
            else{
                node->right = insert(target, node->right, is_full_word);
            }
        }

        else if(is_full_word){
            node->is_full_word = 1;
        }

        node->update_height();
        return balance(node);
    }

    int search(string target, BinaryNode* node){
        if(!node) return -1;

        if(target == node->data){
            return node->is_full_word;
        }

        if(target < node->data){
            return search(target, node->left);
        }

        return search(target, node->right);
    }

    void insert_value(string target, bool is_full_word){
        if(!root){
            root = new BinaryNode(target, is_full_word);
        }
        else{
            root = insert(target,root, is_full_word);
        }
    }



public: 
    void insert_string(string str){
        if(str == "") {
            return;
        }

        string curr;
        for(int i = 0; i < str.size(); i++){
            curr += str[i];
            insert_value(curr, i == str.size() - 1);
        }
    }

    bool word_exist(string str){
        return search(str, root) == 1;
    }

    bool prefix_exist(string str){
        return search(str, root) != -1;
    }

};

int main(){
    AVLTree tree;
    tree.insert_string("salah");
    cout << tree.prefix_exist("salah");
    
}
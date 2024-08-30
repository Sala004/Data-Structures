#include <iostream>
#include <utility>
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

    bool search(int target, BinaryNode* node){
        if(!node) return false;

        if(target < node->data){
            return search(target, node->left);
        }
        else if(target > node->data){
            return search(target, node->right);
        }
        else{
            return true;
        }
    }

    int smallest_greater(int target, BinaryNode* node){
        if(!node){
            return -1;
        }

        else if(target <= node->data){
            int leftRes = smallest_greater(target, node->left);
            if(leftRes != -1){
                return leftRes;
            }
            return node->data;
        }

        else{
            return smallest_greater(target, node->right);
        }

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


    pair<bool, int> lower_bound(int target){
        bool found = search(target, root);
        int next_bigger = smallest_greater(target, root);

        return {found, next_bigger};
    }
};

/*
    The question here: Why should I use AVL Tree? 
    In this search operation, I need to ensure that it always takes 𝑂(log 𝑛) time.
    AVL Tree gurantee this, because it is self-balancing
    But BST could take O(n) in worst case
*/
int main(){
    AVLTree tree;
    tree.insert_value(2);
    tree.insert_value(5);
    tree.insert_value(10);
    tree.insert_value(13);
    tree.insert_value(15);
    tree.insert_value(20);
    tree.insert_value(40);
    tree.insert_value(50);
    tree.insert_value(70);

    int num;
    cin >> num;
    
    pair<bool, int> res = tree.lower_bound(num);
    cout << res.first << " " << res.second << endl;
}
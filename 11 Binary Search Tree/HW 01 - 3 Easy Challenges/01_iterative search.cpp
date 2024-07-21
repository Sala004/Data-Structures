#include <iostream>
using namespace std;

struct TreeNode{
    int val {};
    TreeNode* left {};
    TreeNode* right {};
    TreeNode(int val): val(val) {}
};

struct BinaryTree
{
    TreeNode* root {};
    BinaryTree(int rootValue):
        root(new TreeNode(rootValue)) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root){
            if(val == root->val) return root;
            else if (val < root->val) root = root->left;
            else  root = root->right;
            
        }

        return nullptr;
    }
};

int main(){

    return 0;
}
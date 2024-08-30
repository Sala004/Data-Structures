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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);

        TreeNode* curr = root;

        while(curr){
            if(curr->val > val){
                if(curr->left) curr = curr->left;
                else{
                    curr->left = new TreeNode(val);
                    break;
                }
            }

            if(curr->val < val){
                if(curr->right) curr = curr->right;
                else{
                    curr->right = new TreeNode(val);
                    break;
                }
            }
        }

        return root;
    }
};

int main(){
    
    return 0;
}
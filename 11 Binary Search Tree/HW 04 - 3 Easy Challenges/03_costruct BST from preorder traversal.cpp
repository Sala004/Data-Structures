//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Solution {
public:
    void insert(TreeNode* root, int key){
        if(key < root->val){
            if(!root->left){
                root->left = new TreeNode(key);
            }
            else{
                insert(root->left, key);
            }
        }

        else if(key > root->val){
            if(!root->right){
                root->right = new TreeNode(key);
            }
            else{
                insert(root->right, key);
            }
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i = 1; i < preorder.size(); i++){
            insert(root, preorder[i]);
        }

        return root;
    }
};
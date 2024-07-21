#include <iostream>
using namespace std;

struct TreeNode{
    int val {};
    TreeNode* left {};
    TreeNode* right {};
    TreeNode(int val): val(val) {}
};

class Solution {
public:
    bool isBST(TreeNode* root, long mn = LONG_MIN, long mx = LONG_MAX){

        bool status = mn < root->val && root->val < mx;

        if(!status) return false;

        bool left = !root->left || isBST(root->left, mn, root->val);
        if(!left) return false;

        bool right = !root->right || isBST(root->right, root->val, mx);
        return right;
    }
};

int main(){
    return 0;
}
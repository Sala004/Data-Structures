#include <iostream>
#include <queue>
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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> right;
        queue<TreeNode*> left;

        right.push(root->right); 
        left.push(root->left); 

        while(!right.empty() && !left.empty()){
            TreeNode* currR = right.front(); 
            TreeNode* currL = left.front(); 
            right.pop(); 
            left.pop();

            if(!currR && !currL) continue;
            if(!currR || !currL) return false; 
            if(currR->val != currL->val){ 
                return false;
            }


            right.push(currR->right); 
            left.push(currL->left);
            right.push(currR->left);
            left.push(currL->right);

        }

        return right.empty() && left.empty();
    }
};
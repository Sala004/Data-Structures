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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        int curr = root->val;
        if(p->val < curr && q->val < curr){
            return lowestCommonAncestor(root->left, p, q);
        }

        if(p->val > curr && q->val > curr){
            return lowestCommonAncestor(root->right, p, q);
        }

        return root;
    }
};

int main(){

    return 0;
}
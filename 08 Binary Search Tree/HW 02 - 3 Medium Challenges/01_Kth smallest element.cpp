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
    void postTraversal(TreeNode* root, int& count, int k, int &res){
        if(!root){
            return;
        }

        postTraversal(root->left, count, k, res);
        count++;
        if(k == count){
            res = root->val;
            return;
        }
        postTraversal(root->right, count, k, res);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int res = -1;
        postTraversal(root, count, k, res);
        return res;
    }
};

int main(){

    return 0;
}
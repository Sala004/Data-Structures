#include <iostream>
#include <vector>
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

class Solution{
public:
    TreeNode* sortedArrayToBST(vector<int> &nums){
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }

    TreeNode* sortedArrayToBST(vector<int>& values, int start, int end) {
        if(start > end) return nullptr;

        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(values[mid]);
        root->left = sortedArrayToBST(values, start, mid - 1);
        root->right = sortedArrayToBST(values, mid + 1, end);

        return root;
    }
};

int main(){

    return 0;
}
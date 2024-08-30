#include <iostream>
#include <vector>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        bool left = true;
        vector<vector<int>> res;
        int level = 0;


        queue<TreeNode*> nodes;
        nodes.push(root);

        while(!nodes.empty()){
            int size = nodes.size();
            vector<int> levelNodes;

            while(size--){
                TreeNode* curr = nodes.front();
                levelNodes.push_back(curr->val);
                nodes.pop();


                if(curr->left){
                    nodes.push(curr->left);
                }

                if(curr->right){
                    nodes.push(curr->right);
                }
            }

            if(!left){
                reverse(levelNodes.begin(), levelNodes.end());
            }

            res.push_back(levelNodes);
            left = !left;
        }

        return res;
    }
};
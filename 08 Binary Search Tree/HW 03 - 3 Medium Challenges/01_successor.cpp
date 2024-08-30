#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

struct TreeNode {
	int val { };
	TreeNode* left { };
	TreeNode* right { };
    TreeNode* parent { };
	TreeNode(int val) : val(val) { }
};

class BinarySearchTree {
    TreeNode* root { };

    void _insert(TreeNode* root, int target) {
        if (target < root->val) {
            if (!root->left) {
                root->left = new TreeNode(target);
                root->left->parent = root;
            } else {
                _insert(root->left, target);
            }
        } else if (target > root->val) {
            if (!root->right) {
                root->right = new TreeNode(target);
                root->right->parent = root;
            } else {
                _insert(root->right, target);
            }
        }
    }

    int min_value(TreeNode* cur) {
        if (!cur) return -1; // Handle nullptr case
        while (cur && cur->left)
            cur = cur->left;
        return cur->val;
    }

    TreeNode* search(TreeNode* root, int target) {
        if (!root)
            return nullptr;

        if (target == root->val)
            return root;

        if (target < root->val)
            return search(root->left, target);

        return search(root->right, target);
    }

public:
    BinarySearchTree(int root_value) : root(new TreeNode(root_value)) { }

    void insert(int target) {
        if (!root)
            root = new TreeNode(target);
        else
            _insert(root, target);
    }

    pair<bool, int> successor(int target) {
        TreeNode* child = search(root, target);

        if (!child) return make_pair(false, -1); // If target not found

        if (child->right) // Must have it in min of right
            return make_pair(true, min_value(child->right));

        TreeNode* parent = child->parent;

        // Cancel chain of ancestors I am BIGGER than them
        while (parent && parent->right == child) {
            child = parent;
            parent = child->parent;
        }

        if (parent)
            return make_pair(true, parent->val);
        return make_pair(false, -1);
    }
};

int main() {
    BinarySearchTree tree(50);
    tree.insert(20);
    tree.insert(45);
    tree.insert(70);
    tree.insert(73);
    tree.insert(35);
    tree.insert(15);
    tree.insert(60);

    vector<int> v { 15, 20, 35, 45, 50, 60, 70, 73 }; 

    for (int i = 0; i < (int)v.size(); ++i) {
        cout << v[i] << " ";
        pair<bool, int> p = tree.successor(v[i]);

        if (p.first)
            cout << p.second << "\n";
        else
            cout << "NA\n";
    }

    return 0;
}
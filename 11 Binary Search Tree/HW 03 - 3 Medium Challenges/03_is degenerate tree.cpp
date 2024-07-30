#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

class BinarySearchTree {
private:
	int data { };
	BinarySearchTree* left { };
	BinarySearchTree* right { };

public:

	BinarySearchTree(int data, BinarySearchTree* left = nullptr, BinarySearchTree* right = nullptr) :
			data(data), left(left), right(right) {
	}

    void insert(int target) {
		if (target < data) {
			if (!left) {
				left = new BinarySearchTree(target);
			} else
				left->insert(target);
		} else if (target > data) {
			if (!right)
				right = new BinarySearchTree(target);
			else
				right->insert(target);
		} // else: exists already
	}

    void PreorderTraversal(vector<int> &preorder){
        preorder.push_back(data);
        if(left) left->PreorderTraversal(preorder);
        if(right) right->PreorderTraversal(preorder);
    }

    bool isDegenerate(vector<int> &pre){
        int len = pre.size();
        int max_val = INT_MAX, min_val = INT_MIN; 
        for (int i = 1; i < len; i++) {
            if (pre[i] < min_val || pre[i] > max_val) {
                return false;
            }

            if (pre[i] < pre[i-1]) {
                max_val = pre[i-1];
            } else {
                min_val = pre[i-1];
            }
        }

        return true;
    }

};

int main(){
    BinarySearchTree tree(100);
    tree.insert(70);
    tree.insert(101);

    vector<int> preorder;
    tree.PreorderTraversal(preorder);
    cout << tree.isDegenerate(preorder);
}
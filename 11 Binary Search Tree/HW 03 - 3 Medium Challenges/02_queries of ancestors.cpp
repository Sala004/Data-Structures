#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
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

    	void successor_queries(deque<int> & queries, vector<int> &answer, vector<int> &traversal) {
		if (queries.empty())
			return;

		if (left && queries.front() < data) {
			left->successor_queries(queries, answer, traversal);

			if (queries.empty())
				return;
		}

		// If the last element added in the traversal is the requested element
		// Then the current element is its successor!
		if (!traversal.empty() && traversal.back() == queries.front()) {
			answer.push_back(data);
			queries.pop_front();

			if (queries.empty())
				return;
		}
		traversal.push_back(data);

		// Observe the = : If target equal the cur data and we have right, then successor on right

		if (right && queries.front() >= data)
			right->successor_queries(queries, answer, traversal);
	}
};

int main(){
    BinarySearchTree tree(50);
    tree.insert(20);
    tree.insert(45);
    tree.insert(70);
    tree.insert(73);
    tree.insert(35);
    tree.insert(15);
    tree.insert(60);

    deque<int> queries { 15, 20, 60 }; 
    for(int i = 0; i < queries.size(); i++){   
        cout << "Query " << i + 1 << ": " << queries[i] << endl; 
    }
    vector <int> res;
    vector <int> traversal;
    tree.successor_queries(queries, res, traversal);

    for(int i = 0; i < res.size(); i++){
        cout << "Successor " << i + 1 << ": " << res[i] << endl;
    }

    return 0;

}
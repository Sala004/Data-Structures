#include<vector>
#include<queue>
#include<iostream>
#include<cassert>
using namespace std;

class BinaryTree {
private:
	int data { };
	BinaryTree* left { };
	BinaryTree* right { };

public:

	BinaryTree(int data) :
			data(data) {
	}

	void add(vector<int> values, vector<char> direction) {
		assert(values.size() == direction.size());
		BinaryTree* current = this;
		// iterate on the path, create all necessary nodes
		for (int i = 0; i < (int) values.size(); ++i) {
			if (direction[i] == 'L') {
				if (!current->left)
					current->left = new BinaryTree(values[i]);
				else
					assert(current->left->data == values[i]);
				current = current->left;
			} else {
				if (!current->right)
					current->right = new BinaryTree(values[i]);
				else
					assert(current->right->data == values[i]);
				current = current->right;
			}
		}
	}

    void level_order_traversal(){
        priority_queue<pair<int, BinaryTree*>> heaps[2];
        int flag = 0;
        heaps[flag].push({data, this});

        while(!heaps[flag].empty()){
            int sz = heaps[flag].size();

            while(sz--){
                pair<int, BinaryTree*> curr_pair = heaps[flag].top();
                heaps[flag].pop();
                BinaryTree* curr_node = curr_pair.second;
                cout << curr_pair.first << " ";

                if(curr_node->left){
                    heaps[!flag].push({curr_node->left->data, curr_node->left});
                }

                if(curr_node->right){
                    heaps[!flag].push({curr_node->right->data, curr_node->right});
                }
            }

            cout << endl;
            flag = !flag;
        }
    }

};

int main(){

    BinaryTree tree(1);

	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add( { 3, 6, 15 }, { 'R', 'R', 'L' });

	tree.add( { 2, 5, 13 }, { 'L', 'R', 'L' });
	tree.add( { 3, 6, 12 }, { 'R', 'R', 'R' });
	tree.add( { 3, 14, 15 }, { 'R', 'L', 'L' });
	tree.add( { 3, 14, 16 }, { 'R', 'L', 'R' });

    tree.level_order_traversal();
}
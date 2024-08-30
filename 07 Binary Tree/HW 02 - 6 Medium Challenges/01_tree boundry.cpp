#include <iostream>
#include <vector>
using namespace std;

class BinaryTree{
private:
  
    int data { };
    BinaryTree* left { };
    BinaryTree* right { };

public:
    BinaryTree (int data):
        data(data) {}

    void add(vector<int> values, vector<char> direction){
        BinaryTree* curr = this;

        for(int i = 0; i < values.size(); i++){
            if(direction[i] == 'L'){
                if(!curr->left){
                    curr->left = new BinaryTree(values[i]);
                }
                curr = curr->left;
            }
            else{
                if(!curr->right){
                    curr->right = new BinaryTree(values[i]);
                }
                curr = curr->right;
            }

        }
    }

    void traverseLeftBoundry(){
        cout << data << " ";

        if(!left && !right){
            return;
        }

        else if(left){
            left->traverseLeftBoundry();
        }

        else if(right){
            right->traverseLeftBoundry();
        }

    }
    

};


int main(){
    BinaryTree tree(1);
    tree.add( { 2, 4, 5, 6, 7, 9, 11 }, { 'L', 'L', 'R', 'R', 'L', 'L', 'R' });
	tree.add( { 2, 4, 5, 6, 8 }, { 'L', 'L', 'R', 'R', 'R' });
	tree.add( { 2, 4, 5, 6, 7, 10 }, { 'L', 'L', 'R', 'R', 'L', 'R' });
	tree.add( { 3 }, { 'R' });

    tree.traverseLeftBoundry();
}
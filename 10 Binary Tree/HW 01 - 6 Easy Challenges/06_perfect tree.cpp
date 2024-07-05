#include <iostream>
#include <vector>
#include <cmath>
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

    int treeHeight(){
        int res = 0;
        if(left){
            res = 1 + left->treeHeight();
        }
        if(right){
            res = max(res, right->treeHeight());
        }
        return res;
    }

    int countNodes(int res = 1){
        if(left){
            res = 1 + left->countNodes(res);
        }
        if(right){
            res = 1 + right->countNodes(res);
        }
        return res;
    }


    bool isPerfect(int height){
        
        if(!right && !left){
            return height == 0;
        }
        if(left && !right || !left && right){
            return false; //one child
        }

        return left->isPerfect(height - 1) && right->isPerfect(height - 1);
    }

    bool isPerfectFormula(){
        int h = treeHeight();
        int n = countNodes();
        return pow(2, h + 1) - 1 == n;
    }
    

};


int main(){
    BinaryTree tree(1);
    tree.add({2, 4}, {'L', 'L'});
    tree.add({2, 5}, {'L', 'R'});
    tree.add({3, 10}, {'R', 'L'});
    tree.add({3, 6}, {'R', 'R'});

    int h = tree.treeHeight();
    cout << tree.isPerfect(h) << endl;
    cout << tree.isPerfectFormula() << endl;
}